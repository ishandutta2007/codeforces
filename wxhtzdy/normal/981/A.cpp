#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int ans=0;
  for(int i=0;i<(int)s.length();i++){
    for(int j=i+1;j<(int)s.length();j++){
      bool ok=1;
      for(int k=0;k<j-i+1;k++){
        if(s[i+k]!=s[j-k])ok=0;  
      } 
      if(!ok)ans=max(ans,j-i+1);
    }
  }  
  cout<<ans;
}