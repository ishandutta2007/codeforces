#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  bool ok=1;
  for(int i=0;i<n;i++){
    if(s[i]=='1'&&i>0&&s[i-1]=='1')ok=0;
    if(s[i]=='1'&&i<n-1&&s[i+1]=='1')ok=0;
  }
  if(!ok){cout<<"No";return 0;}
  bool t=1;
  for(int i=0;i<n;i++){
    if((s[i-1]=='0'||i==0)&&s[i]=='0'&&(s[i+1]=='0'||i==n-1))t=0;
  }
  if(!t)cout<<"No";
  else cout<<"Yes";
}