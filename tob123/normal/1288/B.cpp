#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T;
ll A, B;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  while(T--){
    cin >> A >> B;
    ll cnt = 0;
    for(ll i=10; i<=B+10; i*=10){
      if(i-1<=B)
        cnt++;
    }
    cnt *= A;
    cout << cnt << endl;
  }

  return 0;
}