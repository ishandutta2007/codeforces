#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll n = 1e6+10;
const ll INF = 1e6;

int N, K;
vector<int> A;
vector<vector<int>> G;
set<int> S;
vector<int> indOfVal[n];

int toSi[n];
int len[n];
int ri[n];

int ind=0;

void dfs(int cur){
  toSi[cur] = ind++;
  for(int x : G[cur]){
    dfs(x);
  }
  ri[cur] = ind-1;
}

const int size = 1024*1024*2;
const int offset = size/2-1;
ll s[size];
ll u[size];
int par(int x){
  return (x-1)/2;
}
int left(int x){
  return 2*x+1;
}
int right(int x){
  return 2*x+2;
}

void update(int l, int r, ll val, int curl=0, int curr=offset, int cur=0){
  if(l > curr || r < curl){
    return;
  }
  if(l <= curl && r >= curr){
    u[cur] += val;
    s[cur] += val;
    return;
  }
  int m = (curl+curr)/2;
  update(l, r, val, curl, m, left(cur));
  update(l, r, val, m+1, curr, right(cur));
  s[cur] = u[cur] + max(s[left(cur)], s[right(cur)]);
}

ll query(){
  return s[0];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;

  A.resize(N+1);
  G.resize(N+1);
  for(int i=1; i<=N; i++){
    cin >> A[i];
    indOfVal[A[i]].push_back(i);
  }
  for(int i=N; i>=0; i--){
    for(int ind : indOfVal[i]){
      auto it = S.upper_bound(ind);
      if(it == S.end()){
        G[0].push_back(ind);
        //len[ind] = 1;
      }
      else{
        G[*it].push_back(ind);
        //len[ind] = len[*it]+1;
      }
    }
    for(int ind : indOfVal[i]){
      S.insert(ind);
    }
  }

  /*
  for(int i=1; i<=N; i++){
    cout << len[i] << " ";
  }
  cout << endl;
  */

  dfs(0);

  int l = 0;
  for(int i=1; i<=N; i++){
    update(toSi[i], ri[i], 1);
    if(i > K){
      l++;
      update(toSi[i-K], ri[i-K], -INF);
    }
    if(i >= K){
      cout << query() << " ";
    }
  }
  cout << endl;

  return 0;
}