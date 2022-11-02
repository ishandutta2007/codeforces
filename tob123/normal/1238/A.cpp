#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll T, x, y;
  cin >> T;
  while(T--){
    cin >> x >> y;
    if(x - y == 1){
      cout << "NO\n";
    }
    else{
      cout << "YES\n";
    }
  }

  return 0;
}