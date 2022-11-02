#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll T, N, K;
  cin >> T;
  while(T--){
    cin >> N >> K;
    N -= K*K;
    if(N >= 0 && N%2==0){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }

  return 0;
}