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
  ll X;
    cin >> X;
    if(X >= 15 && X%14>0 && X%14 <=6){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }

  return 0;
}