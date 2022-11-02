#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T;
ll N, D;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  while(T--){
    cin >> N >> D;
    ll x = (ll) sqrt(D);
    //cout << N << " " << D << " " << x << endl;
    bool pos = false;
    for(ll i=0; i<=min(N, x+20); i++){
      //cout << i + (D+i)/(i+1) << endl;
      pos |= i + (D+i)/(i+1) <= N;
    }
    if(pos)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}