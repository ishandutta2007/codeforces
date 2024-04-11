#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  string s;
  cin >> s;
  string ans="";
  int se=s.length();
  for(int i=s.length()-1;i>=0;i--){
    if(s[i]!='1'){
      ans+=s[i];
    }
  }
  for(int i=ans.length();i<s.length();i++){
    ans+='1';
  }
  reverse(ans.begin(),ans.end());
  int zero=0,one=0;
  for(int i=0;i<ans.length();i++){
    if(ans[i]=='2') break;
    if(ans[i]=='0') zero++;
    else one++;
  }
  for(int i=0;i<zero;i++){
    ans[i]='0';
  }
  for(int i=zero;i<zero+one;i++){
    ans[i]='1';
  }
  cout << ans << endl;
  return 0;
}