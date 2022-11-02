#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b, T;
  cin >> T;
  for(int i=0; i<T; i++){
    cin >> a >> b;
    if(a > b)
      swap(a, b);
    if(b > 2*a){
      cout << "NO\n";
    }
    else if((a-(b-a)) % 3 == 0){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }

  return 0;
}