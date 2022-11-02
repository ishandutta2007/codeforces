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

const int n = 2200;
const int INF = 1e7;

int TC, N;
string S, T;
int res[n][n];
vector<vector<int>> dp;
vector<int> cnt(26), cnt2(26);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> TC;
  while(TC--){
    cin >> N >> S >> T;
    dp.resize(N+1);
    for(int i=0; i<=N; i++)
      dp[i].resize(N+1);
    for(int i=1; i<=N; i++)
      for(int j=0; j<=N; j++)
        dp[i][j] = INF;
    for(int x=0; x<26; x++)
      cnt2[x] = 0;
    for(int i=1; i<=N; i++){ // over S
      cnt2[S[i-1]-'a']--;
      cnt2[T[i-1]-'a']++;
      for(int x=0; x<26; x++)
        cnt[x] = cnt2[x];
      for(int j=i; j<=N; j++){
        if(S[i-1] == T[j-1]){
          dp[i][j] = dp[i-1][j-1];
        }
        if(j > i){
          dp[i][j] = min(dp[i][j], dp[i][j-1]);
          cnt[T[j-1]-'a']++;
        }
        if(cnt[S[i-1]-'a']>=0)
          dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
      }
      //print(cnt);
    }
    //print(dp);
    cout << (dp[N][N]<INF ? dp[N][N] : -1) << endl;
  }
}