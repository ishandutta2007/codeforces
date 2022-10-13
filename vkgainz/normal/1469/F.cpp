#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 5e5+5;
struct state {
  int dist, numIn;
  bool white;
  state(int a, int b, bool c):
    dist(a), numIn(b), white(c)
  {
    
  }
};
bool work(ll x, vector<int> &l, int &k) {
  queue<state> pq;
  pq.push(state(0, 1, 1));
  ll numLess = 1LL;
  int idx = l.size() - 1;
  while(!pq.empty() && idx >= 0 && numLess < k) {
    state curr = pq.front();
    pq.pop();
    if(curr.dist >= x - 1) {
      break;
    }
    if(!curr.white) {
      pq.push(state(curr.dist + 1, curr.numIn, true));
    }
    else {
      int currL = l[idx--];
      int left = (currL-1)/2, right = currL/2;
      --numLess;
      numLess+=min((ll)left, (ll)x-curr.dist-1);
      numLess+=min((ll)right, (ll)x-curr.dist-1);
      pq.push(state(curr.dist + 1, left, false));
      pq.push(state(curr.dist + 1, right, false));
      ++curr.dist;
      --curr.numIn;
      if(curr.numIn >= 1) {
        pq.push(curr);
      }
    }
  }
  return numLess >= k;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k; cin >> n >> k;
  vector<int> l(n);
  for(int i=0;i<n;i++)
    cin >> l[i];
  //what is the optimal order to add?
  sort(l.begin(), l.end());
  ll num = 1LL;
  for(int i=0;i<n;i++) {
    num+=l[i]-2;
  }
  if(num < k) {
    cout << -1 << "\n";
    return 0;
  }
  ll lo = 0, hi = 1e15; // [lo, hi]
  for(int i=0;i<55;i++) {
    ll mid = (lo+hi)/2;
    if(work(mid, l, k)) {
      hi = mid;
    }
    else {
      lo = mid+1;
    }
  }
  cout << lo << "\n";
  //given parameter x
  
}