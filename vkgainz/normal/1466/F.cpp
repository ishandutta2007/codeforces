#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 5e5+5;

//edge from cycle to cycle is redundant
//k=1 means self loop -> create new cycle
//edge from tree to tree ==> num = 2^sz - 1
//use dsu?

int par[MX], sz[MX];
int numEdge[MX];
bool work[MX];
int find(int x) {
  if(x==par[x]) return x;
  return par[x] = find(par[x]);
}
bool put;
//take k=1 case separately?
vector<pair<pair<int, int>, int>> merged;
int idx;
void mergeSame(int i) {
  int x = find(i);
  if(work[x]) {
    put = false;
  }
  else {
    merged.push_back({{i, i}, idx});
    work[x] = true;
    put = true;
    ++numEdge[x];
    if(numEdge[x]==sz[x])
      work[x] = true;
  }
}
void merge(int i, int j) {
  int x = find(i), y = find(j);
  if(x==y) return;
  if(work[x] && work[y])
    return;
  if(sz[x]<sz[y])
    swap(x, y);
  merged.push_back({{i, j}, idx});
  if(!work[x] && !work[y]) {
    sz[x]+=sz[y];
    par[y] = x;
    numEdge[x]+=numEdge[y]+1;
  }
  else if(work[x] && !work[y]) {
    sz[x]+=sz[y];
    par[y] = x;
    work[y] = true;
    work[x] = true;
    numEdge[x]+=numEdge[y]+1;
  }
  else {
    sz[x]+=sz[y];
    par[y] = x;
    work[y] = true;
    work[x] = true;
    numEdge[x]+=numEdge[y]+1;
  }
  if(numEdge[x]==sz[x])
    work[x] = true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for(int i=0;i<MX;i++) {
    par[i] = i, sz[i] = 1, numEdge[i] = 0, work[i] = false;
  }
  for(int i=0;i<n;i++) {
    int k; cin >> k;
    put = false;
    if(k==1) {
      int x; cin >> x;
      --x;
      mergeSame(x);
    }
    else {
      int a, b; cin >> a >> b;
      --a, --b;
      merge(a, b);
    }
    ++idx;
  }
  ll num = 1LL;
  ll mod = 1e9+7;
  vector<int> in;
  int numTree = 0;
  set<int> s;
  for(int i=0;i<MX;i++) {
    s.insert(find(i));
  }
  for(auto &it : s) if(!work[it]) ++numTree;
  for(int i=0;i<MX-numTree;i++) {
    num = num*1LL*2%mod;
  }
  if(num<0) num+=mod;
  cout << num << " " << merged.size() << "\n";
  for(auto &it : merged) {
    cout << it.s+1 << " ";
  }
  cout << "\n";
}