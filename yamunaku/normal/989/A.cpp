#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  string s;
  cin >> s;
  bool a,b,c;
  for(int i=1;i<s.length();i++){
    a=b=c=false;
    for(int j=-1;j<=1;j++){
      if(s[i+j]=='A'){
        a=true;
      }else if(s[i+j]=='B'){
        b=true;
      }else if(s[i+j]=='C'){
        c=true;
      }
    }
    if(a&b&c){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}