#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int first1(string x, int ind){
  for(int i=sz(x)-1-ind; i>=0; i--){
    if(x[i] == '1')
      return sz(x)-i-1;
  }
  exit(1);
}

int main(){
  int T;
  cin >> T;
  while(T--){
    string x, y;
    cin >> x >> y;
    int i2 = first1(y, 0);
    int i1 = first1(x, i2);
    int res;
    res = i1-i2;
    cout << res << "\n";
  }
  return 0;
}