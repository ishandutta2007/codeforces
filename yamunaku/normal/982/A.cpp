#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int now=-1;
  for(int i=0;i<n;i++){
    if(s[i]=='1'){
      if(now==-1){
        if(i>1){
          cout << "No" << endl;
          return 0;
        }
        now=i;
      }else{
        if(i-now==1||i-now>3){
          cout << "No" << endl;
          return 0;
        }
        now=i;
      }
    }
  }
  if(now==-1||now<=n-3){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}