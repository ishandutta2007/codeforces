#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T, N, K;
string S;
string res;

/*
void solve(int si){
  if(si == N)
    return;
  if(N < si+K){
    res.push_back(S[si]);
    return;
  }
  if(S[si] == S[si+K-1]){
    res.push_back(S[si]);
    solve(si+K);
  }
  else{
    res.push_back(
  }
}
*/

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> K;
    cin >> S;
    res.clear();
    sort(S.begin(), S.end());
    if(K == 1)
      cout << S << endl;
    else{
      if(S[0] == S[K-1]){
        if(K < N && S[K] == S[N-1]){
          cout << S[0] << S.substr(K, (N-1)/K) << endl;
        }
        else{
          cout << S.substr(K-1) << endl;
        }
      }
      else{
        cout << S[K-1] << endl;
      }
    }
  }
}