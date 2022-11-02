#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

ll N, M, Q, t;

ll gcd ( ll a , ll b ) {
  ll tmp ;
  while ( b ) { a %= b ; tmp = a ; a = b ; b = tmp ;}
  return a ;
}

ll sect(ll a, ll b){
  if(a == 1){
    b /= (N/t);
  }
  else{
    b /= (M/t);
  }
  return b;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> Q;
  t = gcd(N, M);
  ll sx, sy, ex, ey;
  for(int i=0; i<Q; i++){
    cin >> sx >> sy >> ex >> ey;
    sy--; ey--;
    ll sects = sect(sx, sy);
    ll secte = sect(ex, ey);
    if(sects == secte){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }

  return 0;
}