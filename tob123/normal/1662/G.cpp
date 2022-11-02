#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

const int n = 1e6;
//const int n = 6;

int N;
vector<vector<int>> G;
ll cnt[n];
ll sumPath[n];
ll total[n];
ll res = 0;

ll knap(int cur, int par){
  map<ll, int> w;
  for(int x : G[cur]){
    ll curw;
    if(x == par){
      curw = N - cnt[cur];
    }
    else
      curw = cnt[x];
    while(w[curw] == 2){
      w[curw] = 1;
      curw *= 2;
    }
    w[curw]++;
  }
  bitset<n/2+1> dp;
  dp.set(0);
  for(auto [curw, wcnt] : w){
    for(int i=0; i<wcnt; i++){
      dp |= dp << curw;
    }
  }
  for(int i=N/2; i>=0; i--){
    if(dp[i])
      return i;
  }
  return 0;
}

void printP(){
  cout << "sp: ";
  for(int i=0; i<N; i++){
    cout << sumPath[i] << " ";
  }
  cout << endl;
}

void dfs(int cur, int par){
  ll mx = 0;
  //ll fullOver = 0;
  for(int x : G[cur]){
    if(x == par) continue;
    dfs(x, cur);
    //fullOver += (cnt[x]) * (cnt[cur]+1);
    cnt[cur] += cnt[x];
    if(cnt[cur] > mx){
      mx = cnt[x];
    }
    sumPath[cur] += sumPath[x];
  }
  cnt[cur] += 1;
  sumPath[cur] += cnt[cur];
  /*
  total[cur] = sumPath[cur];
  */
  if(N-cnt[cur] > mx){
    mx = N-cnt[cur];
  }
  //cout << "tot: " << total[cur] << endl;
  //cout << "fullOver: " << fullOver << endl;
  //ll oth = N*(N-1)/2 + N - total[cur] - fullOver ;
  //total[cur] += oth;
  //cout << "oth: " << oth << endl;
  if(mx <= N/2){
    ll x = knap(cur, par);
    total[cur] += (x) * (N-x-1);
  }
  else
    total[cur] += (mx) * (N-mx-1);
  //cout << "full: " << total[cur] << endl;
  //cout << endl << endl;
}

void dfs2(int cur, int par){
  if(par != -1)
    //sumPath[cur] = sumPath[par] - sumPath[cur] - cnt[cur];
    sumPath[cur] = sumPath[par] - cnt[cur] + (N-cnt[cur]);
  for(int x : G[cur]){
    if(x == par) continue;
    //sumPath[cur] += sumPath[x];
    dfs2(x, cur);
  }
  //sumPath[cur] += N;
  //cout << cur << " sumP: " << sumPath[cur] << endl;
  total[cur] += sumPath[cur];
  res = max(res, total[cur]);
} 

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  G.resize(N);
  for(int i=1; i<N; i++){
    int p;
    cin >> p;
    p--;
    G[i].push_back(p);
    G[p].push_back(i);
  }
  //printP();
  dfs(0, -1);
  //printP();
  dfs2(0, -1);
  //printP();
  cout << res << endl;
}