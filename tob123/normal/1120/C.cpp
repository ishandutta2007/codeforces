#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, A, B;
string S[5050];
int dp[5050];

bool substr(int l, int r, int to){
  string x = "";
  for(int i=l; i<r; i++){
    x.push_back(S[r][i]);
  }
  //cout << l << " " << r << " -> " << to << ": " << x << endl;
  if(S[to].find(x) != string::npos)
    return true;
  return false;
}

int main(){
  cin >> N >> A >> B;
  char c;
  for(int i=1; i<=N; i++){
    cin >> c;
    S[i] = S[i-1];
    S[i] += c;
    dp[i] = dp[i-1]+A;
    int l=0, r=i;
    /*
    int ind = i-1;
    for(int j=i-1; j>=0; j--){
      while(ind >= 0 && S[ind] != S[j]){
        ind--;
      }
      if(ind < 0){
        break;
      }
      else{
        dp[i] = min(dp[i], dp[j]+B);
      }
    }
    */
    while(l < r){
      int m = (l+r)/2;
      if(substr(m, i, m)){
        r = m;
      }
      else{
        l = m+1;
      }
    }
    if(l < i){
      dp[i] = min(dp[i], dp[l]+B);
    }
    //cout << i << ": " << dp[i] << endl;
  }

  cout << dp[N] << endl;

  return 0;
}