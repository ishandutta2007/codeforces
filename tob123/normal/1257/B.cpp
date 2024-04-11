#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    ll X, Y;
    cin >> X >> Y;
    bool b = false;
    if(Y <= X){
      b = true;
    }
    if(X == 2 && Y == 3)
      b = true;
    if(X > 3)
      b = true;
    if(b){
      cout << "yes" << endl;
    }
    else{
      cout << "no" << endl;
    }
  }

  return 0;
}