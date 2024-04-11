#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 2e5+5;
vector<int> adj[MX];
vector<int> in[MX];
int p[MX];
int par[MX];
ll sz[MX];
int num[MX]; //for pie
ll temp[MX];
ll ret[MX];
bool put[MX];
int find(int x) {
  if(x==par[x])
    return x;
  return par[x] = find(par[x]);
}
ll ans;
void merge(int x, int y) {
  int a = find(x), b = find(y);
  if(a==b)
    return;
  if(sz[b]>sz[a])
    swap(a, b);
  ans-=sz[a]*1LL*(sz[a]+1)/2;
  ans-=sz[b]*1LL*(sz[b]+1)/2;
  sz[a]+=sz[b];
  par[b] = a;
  ans+=sz[a]*1LL*(sz[a]+1)/2;
}
void dfs(int curr, int parent) {
  if(parent!=-1)
    p[curr] = parent;
  for(int next : adj[curr]) {
    if(next==parent) continue;
    dfs(next, curr);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n;
  int a[n];
  for(int i=0;i<n;i++)
    cin >> a[i], par[i] = i, sz[i] = 1;
  for(int i=0;i<n;i++) {
    for(int j=1;j*j<=a[i];j++) {
      if(j*j==a[i]) {
        in[j].push_back(i);
      }
      else {
        if(a[i]%j==0) {
          in[j].push_back(i);
          in[a[i]/j].push_back(i);
        }
      }
    }
  }
  for(int i=0;i<n-1;i++) {
    int x, y; cin >> x >> y;
    --x, --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  p[0] = 0;
  dfs(0, -1);
  num[1] = 1;
  for(int i=1;i<MX;i++) {
    for(int j=2*i;j<MX;j+=i) {
      num[j]-=num[i];
    }
  }
  for(int i=1;i<=200000;i++) {
    //calc for i
    ans = in[i].size();
    for(int idx : in[i]) {
      put[idx] = 1;
      sz[idx] = 1;
      par[idx] = idx;
    }
    for(int idx : in[i]) {
      //merge idx w parent of idx
      if(put[p[idx]])
        merge(idx, p[idx]);     
    }
    //unmerge everything
    for(int idx : in[i]) {
      sz[idx] = 1;
      par[idx] = idx;
      put[idx] = 0;
    }
    temp[i] = ans;
  }
  //pie it out
  for(int i=1;i<MX;i++) {
    for(int j=i;j<MX;j+=i) {
      ret[i]+=temp[j]*1LL*num[j/i];
    }
  }
  for(int i=1;i<=200000;i++) {
    if(ret[i]>0)
      cout << i << " " << ret[i] << "\n";
  }

}