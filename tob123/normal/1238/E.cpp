#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N, M;
string S;
int G[20][20];

int sum[1<<20];
int dp[1<<20];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  cin >> S;
  for(int i=1; i<N; i++){
    if(S[i] != S[i-1]){
      G[S[i]-'a'][S[i-1]-'a']++;
      G[S[i-1]-'a'][S[i]-'a']++;
    }
  }
  dp[0] = sum[0] = 0;
  for(int m=1; m<1<<M; m++){
    dp[m] = 1e7;
    for(int i=0; i<M; i++){
      if((1<<i) & m){
        int cur = dp[m ^ (1<<i)];
        int s = sum[m ^ (1<<i)];
        for(int j=0; j<M; j++){
          if((1<<j) & m){
            s -= G[i][j];
          }
          else{
            s += G[i][j];
          }
        }
        //cout << m << " : " << i << " -> " << s << endl;
        cur += s;
        if(cur < dp[m]){
          dp[m] = cur;
          sum[m] = s;
        }
      }
    }
  }
  /*
  for(int i=0; i<1<<M; i++){
    bitset<4> b(i);
    cout << b << ": " << dp[i] << " " << sum[i] << endl;
  }
  */
  cout << dp[(1<<M)-1] << endl;

  return 0;
}