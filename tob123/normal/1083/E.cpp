#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef tuple<ll, ll, ll> pdd;
typedef pair<ll, ll> pd;

int N;
vector<pdd> P;
vector<pd> cur;

ld schnitt(pd a, pd b){
  return ((ld)(a.first - b.first)) / (b.second-a.second);
}

ll searchBest(ll y){
  int l = 0, r = cur.size()-1;
  while(l < r){
    int m = (l+r)/2;
    if(schnitt(cur[m], cur[m+1]) < y){
      r = m;
    }
    else{
      l = m+1;
    }
  }
  return cur[l].first + cur[l].second * y;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin >> N;
  for(int i=0; i<N; i++){
    ll x, y, a;
    cin >> x >> y >> a;
    P.push_back({y, x, a});
  }
  sort(P.begin(), P.end());

  cur.push_back({0, 0});
  for(auto t : P){
    ll x, y, a;
    tie(y, x, a) = t;

    ll b = searchBest(x);
    pd nxt = {b + x * y - a, -y};
    if(nxt.first > cur[cur.size()-1].first){
      while(cur.size() >= 2){
        if(schnitt(cur[cur.size()-2], nxt) > schnitt(cur[cur.size()-1], cur[cur.size()-2])){
          cur.pop_back();
        }
        else{
          break;
        }
      }
      cur.push_back(nxt);
    }
  }
  cout << cur[cur.size()-1].first << endl;

  return 0;
}