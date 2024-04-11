#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    ll a, b, c, d, x, y, x1, y1, x2, y2;
    cin >> a >>b >> c >> d;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    ll newx = x+b-a;
    ll newy = y+d-c;
    if(newx <= x2 && newx >= x1 && newy <= y2 && newy >= y1 && (a+b==0 || x1 != x2) && (c+d==0 || y1 != y2)){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }

  return 0;
}