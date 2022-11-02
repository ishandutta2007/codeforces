#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,bool> pib;
typedef tuple<int,int,int> ti;

const int n = 5e5+10;
const ll MOD = 998244353;

int N, K, M;
int L[n], R[n], X[n];
vector<ti> A;
int cnt[n];
bool vis[n];
ll dp[n];
ll to[n];
ll pw[n];

ll calc(){
  sort(A.begin(), A.end());
  stack<int> S;
  fill_n(vis, M+1, true);
  for(auto t : A){
    int l, r, ind; tie(l,r,ind) = t;
    r *= -1;
    //cerr << "A: " << l << " " << r << " " << ind << endl;
    while(S.size() && R[S.top()] >= R[ind]){
      vis[S.top()] = false;
      S.pop();
    }
    S.push(ind);
  }
  vector<int> X;
  X.push_back(M);
  L[M] = R[M] = 0;
  for(int i=0; i<sz(A); i++){
    int ind = get<2>(A[i]);
    if(vis[ind]){
      X.push_back(ind);
      //cerr << L[ind] << "--" << R[ind] << endl;
    }
  }
  X.push_back(M+1);
  L[M+1] = R[M+1] = N+1;
  //cerr << endl;
  fill_n(dp, M+2, 0);
  fill_n(to, M+2, 0);
  dp[0] = 1;
  deque<ti> Q;
  for(int i=1; i<sz(X); i++){
    if(i != 1)
      dp[i] = dp[i-1];
    //cerr << "vis " << X[i] << ": " << L[X[i]] << " " << R[X[i]] << endl;
    Q.push_back({R[X[i-1]]+1, R[X[i]], i-1});
    to[i-1] = pw[cnt[R[X[i]]]-cnt[R[X[i-1]]]]-1+MOD;
    to[i-1] %= MOD;
    dp[i] += to[i-1]*dp[i-1];
    dp[i] %= MOD;
    while(get<0>(Q[0]) < L[X[i]]){
      int l, r, ind; tie(l, r, ind) = Q[0];
      if(r < L[X[i]]){
        Q.pop_front();
        dp[i] -= to[ind]*dp[ind]%MOD;
        dp[i] = (dp[i]+MOD)%MOD;
        to[ind] = 0;
      }
      else{
        dp[i] -= dp[ind]*to[ind]%MOD;
        dp[i] = (dp[i]+MOD)%MOD;
        l = L[X[i]]; get<0>(Q[0]) = l;
        to[ind] = (pw[cnt[r]-cnt[l-1]]-1)*pw[cnt[l-1]-cnt[R[X[ind]]]]%MOD;
        dp[i] += dp[ind]*to[ind];
        dp[i] = (dp[i]+MOD)%MOD;
      }
    }
    /*
    for(int j=0; j<=i; j++){
      cerr << dp[j] << " " << to[j] << "; ";
    }
    cerr << endl;
    */
  }
  return dp[sz(X)-1];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  pw[0] = 1;
  for(int i=1; i<n; i++){
    pw[i] = 2*pw[i-1]%MOD;
  }
  cin >> N >> K >> M;
  for(int i=0; i<M; i++){
    cin >> L[i] >> R[i] >> X[i];
  }
  ll res = 1;
  for(int b=0; b<K; b++){
    A.clear();
    fill_n(cnt, N+10, 0);
    for(int i=0; i<M; i++){
      if(X[i]&(1<<b)){
        cnt[L[i]]++;
        cnt[R[i]+1]--;
      }
      else{
        A.push_back({L[i], -R[i], i});
      }
    }
    for(int i=1; i<N+5; i++){
      cnt[i] += cnt[i-1];
    }
    for(int i=0; i<N+5; i++){
      if(!cnt[i])
        cnt[i] = 1;
      else
        cnt[i] = 0;
    }
    for(int i=1; i<N+5; i++){
      cnt[i] += cnt[i-1];
    }
    //cerr << "calc bit " << b << endl;
    res *= calc();
    //res = calc();
    //cerr << "res -> " << res << endl;
    res %= MOD;
  }
  cout << res << endl;

  return 0;
}