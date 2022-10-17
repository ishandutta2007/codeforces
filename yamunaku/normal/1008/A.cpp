#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),(-a))

typedef long long LL;

int main(){
  string s;
  cin >> s;
  bool con=false;
  for(int i=0;i<s.length();i++){
    switch(s[i]){
      case 'a':
      case 'i':
      case 'u':
      case 'e':
      case 'o':
        con=false;
        break;
      case 'n':
        if(con){
          cout << "NO" << endl;
          return 0;
        }
        con=false;
        break;
      default:
        if(con){
          cout << "NO" << endl;
          return 0;
        }
        con=true;
    }
  }
  if(con){
  cout << "NO" << endl;
  }else{
  cout << "YES" << endl;
  }
  return 0;
}