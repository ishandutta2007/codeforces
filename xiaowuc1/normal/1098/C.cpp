#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll tri(ll n) {
  return n*(n+1)/2;
}

map<int, ll> dp;
ll minNeed(int n, int b) {
  // you have a tree of N nodes and branching factor of b
  // what is the min you need?
  if(dp.count(n)) return dp[n];
  // root counts for n
  dp[n] = n;
  ll& ret = dp[n];
  n--;
  // n is now the number of children!
  if(n <= b) {
    // just do it?
    ret += n;
    return ret;
  }
  // oh no, recursion
  int defaultSize = n/b;
  int extra = n%b;
  if(extra) ret += extra * minNeed(defaultSize+1, b);
  ret += (b-extra) * minNeed(defaultSize, b);
  return ret;
}

inline ll arith(ll a, ll n) {
  // a + ... + a+n-1, what is the sum?
  ll ret = a*n;
  ret += n*(n-1)/2;
  return ret;
}

int parent[100005];
int numChildAvail[100005];
int depth[100005];

void solve() {
  int n;
  ll maxS;
  cin >> n >> maxS;
  if(tri(n) < maxS) {
    cout << "No\n";
    return;
  }
  if(2*n-1 > maxS) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  int branching = -1;
  for(int b = 1; b <= n-1; b++) {
    dp.clear();
    ll best = minNeed(n, b);
    if(best > maxS) continue;
    branching = b;
    break;
  }
  assert(branching >= 1 && branching <= n-1);
  maxS = tri(n) - maxS;
  map<int, queue<int>> depthToVertices;
  for(int i = 1; i <= n; i++) {
    depth[i] = i;
    depthToVertices[i].push(i);
  }
  for(int i = 2; i <= n; i++) {
    parent[i] = i-1;
    numChildAvail[parent[i]] = branching-1;
  }
  for(int qqq = n; qqq >= 3 && maxS; qqq--) {
    int currV = qqq;
    depthToVertices[depth[currV]].pop();
    if(depthToVertices[depth[currV]].empty()) {
      depthToVertices.erase(depth[currV]);
    }
    if(depth[currV] - maxS - 1 < depthToVertices.begin()->first) {
      // take the lowest
      auto x = depthToVertices.begin();
      maxS -= depth[currV] - x->first - 1;
      int choice = x->second.front();
      parent[currV] = choice;
      depthToVertices[x->first+1].push(currV);
      numChildAvail[currV] = branching;
      depth[currV] = depth[choice]+1;
      if(--numChildAvail[choice] == 0) {
        x->second.pop();
        if(x->second.empty()) depthToVertices.erase(x);
      }
    }
    else {
      int desiredDepth = depth[currV] - maxS - 1;
      queue<int>& from = depthToVertices[desiredDepth];
      int choice = from.front();
      parent[currV] = choice;
      break;
    }
  }
  for(int i = 2; i <= n; i++) {
    cout << parent[i];
    cout << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}