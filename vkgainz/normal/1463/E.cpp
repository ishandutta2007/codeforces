#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MX = 3e5+5;
using ll = long long;
vector<vector<int>> tree;
vector<vector<int>> ret;
vector<int> topSort(int x, vector<vector<int>> graph) {
  int numVis = 0;
  queue<int> q;
  vector<int> in(x);
  for(int i=0;i<x;i++) {
    for(int j : graph[i])
      ++in[j];
  }
  for(int i=0;i<x;i++)
    if(in[i]==0) q.push(i);
  vector<int> ret;
  while(!q.empty()) {
    int x = q.front();
    q.pop();
    ++numVis;
    ret.push_back(x);
    for(int next : graph[x]) {
      --in[next];
      if(in[next]==0) q.push(next);
    }
  }
  if(numVis==x)
    return ret;
  vector<int> a;
  a.push_back(-1);
  return a;
}
int bucket[MX];
int t;
int timeIn[MX];
int sz[MX];
int seg[2*MX];
void upd(int i, int v) {
  seg[i+=MX]+=v;
  while(i>1) {
    i/=2;
    seg[i] = seg[2*i]+seg[2*i+1];
  }
}
int query(int l, int r) {
  l+=MX, r+=MX;
  int ret = 0;
  while(l<r) {
    if(l%2) ret+=seg[l++];
    if(r%2) ret+=seg[--r];
    l/=2, r/=2;
  }
  return ret;
}
void dfs(int curr, int par) {
  timeIn[curr] = t++;
  ++sz[curr];
  for(int next : tree[curr]) {
    if(next==par) continue;
    if(bucket[curr]!=bucket[next])
      ret[bucket[curr]].push_back(bucket[next]);
    dfs(next, curr); 
    sz[curr]+=sz[next];
  }
}
bool vis[MX];
int inTree[MX];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n;
  int k; cin >> k;
  tree = vector<vector<int>>(n);
  for(int i=0;i<n;i++) {
    int q; cin >> q;
    --q;
    if(q>=0) {
      tree[q].push_back(i);
    }
  }
  int nxt[n];
  memset(nxt,-1,sizeof(nxt));
  int in[n];
  memset(in,0,sizeof(in));
  for(int i=0;i<k;i++) {
    int x, y; cin >> x >> y;
    --x, --y;
    nxt[x] = y;
    ++in[y];
  }
  bool work = true;
  int seen = 0;
  for(int i=0;i<n;i++) {
    if(in[i]==0) {
      int curr = i;
      while(curr!=-1) {
        if(vis[curr]) {
          work = false;
          break;
        }
        ++seen;
        vis[curr] = true;
        curr = nxt[curr];
      }
    }
  }
  work = work&&seen==n;
  if(!work) {
    cout << 0 << "\n";
    return 0;
  }
  int num = 0;
  vector<vector<int>> get;
  for(int i=0;i<n;i++) {
    if(in[i]==0) {
      int curr = i;
      vector<int> temp;
      while(curr!=-1) {
        bucket[curr] = num;
        temp.push_back(curr);
        curr = nxt[curr];
      }
      get.push_back(temp);
      ++num;
    }
  }
  for(int i=0;i<n;i++) {
    for(int j : tree[i]) ++inTree[j];
  }
  ret = vector<vector<int>>(num);
  for(int i=0;i<n;i++) {
    if(inTree[i]==0) {
      dfs(i, -1);
    }
  }
  for(int i=0;i<num;i++) {
    for(int j : get[i]) {
      int x = query(timeIn[j], timeIn[j]+sz[j]);
      if(x>0) {
        work = false;
      }
      upd(timeIn[j], 1);
    }
    for(int j : get[i]) {
      upd(timeIn[j], -1);
    }
  }
  vector<int> ans =  topSort(num, ret);
  work = work && (ans[0]!=-1);
  if(!work) {
    cout << 0 << "\n";
    return 0;
  }
  vector<int> ret;
  for(auto &it : ans) {
    for(int j : get[it])
      ret.push_back(j);
  }
  for(auto &it : ret) {
    cout << it+1 << " ";
  }
  cout << "\n";
}