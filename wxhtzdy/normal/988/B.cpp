#include <bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){
  return a.length()<b.length();
}
int main(){
  int n;
  cin>>n;
  string s[n];
  for(int i=0;i<n;i++)cin>>s[i];
  sort(s,s+n,cmp);
  bool ok=1;
  for(int i=1;i<n;i++){
    bool kk=0;
    for(int j=0;j<=(int)s[i].length()-(int)s[i-1].length();j++){
      bool mudja=1;
      for(int k=0;k<(int)s[i-1].length();k++){
        if(s[i-1][k]!=s[i][j+k])mudja=0;
      }
      if(mudja)kk=1;
    }
    if(!kk)ok=0;
  }
  if(!ok){
    cout<<"NO";
    return 0;
  }
  cout<<"YES"<<endl;
  for(int i=0;i<n;i++)cout<<s[i]<<endl;
}