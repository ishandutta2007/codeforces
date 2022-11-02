#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> ti;

const int n = 2e5+10;

int N, M;
vector<pii> G[n];
int visE[n], visV[n];
vector<ti> R;

void dfs(int cur, int par){
  visV[cur] = true;
  for(auto p : G[cur]){
    if(!visV[p.first])
      dfs(p.first, cur);
  }
  vector<pii> A;
  int pe = -1;
  for(auto p : G[cur]){
    if(p.first == par)
      pe = p.second;
    if(p.first != par && !visE[p.second]){
      A.push_back(p);
    }
  }
  if(pe != -1 && sz(A)%2==1)
    A.push_back({par, pe});
  for(int i=1; i<sz(A); i+=2){
    visE[A[i].second] = true;
    visE[A[i-1].second] = true;
    R.push_back({A[i].first, cur, A[i-1].first});
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back({b,i});
    G[b].push_back({a,i});
  }
  for(int i=0; i<N; i++){
    if(!visV[i])
      dfs(i, -1);
  }
  cout << sz(R) << "\n";
  for(auto t : R){
    int a, b, c;
    tie(a, b, c) = t;
    a++; b++; c++;
    cout << a << " " << b << " " << c << "\n";
  }

  return 0;
}