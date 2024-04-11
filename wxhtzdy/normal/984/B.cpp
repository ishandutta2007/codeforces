#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  string s[n];
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  bool ok=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i][j]=='*')continue;
      int cnt=0;
      if(i>0&&s[i-1][j]=='*')cnt++;
      if(i<n-1&&s[i+1][j]=='*')cnt++;
      if(j>0&&s[i][j-1]=='*')cnt++;
      if(j<m-1&&s[i][j+1]=='*')cnt++;
      if(i>0&&j>0&&s[i-1][j-1]=='*')cnt++;
      if(i>0&&j<m-1&&s[i-1][j+1]=='*')cnt++;
      if(i<n-1&&j>0&&s[i+1][j-1]=='*')cnt++;
      if(i<n-1&&j<m-1&&s[i+1][j+1]=='*')cnt++;
      int a=0;
      if(s[i][j]!='.')a=(int)(s[i][j]-'0');
      if(a!=cnt)ok=0;
    }
  }
  if(ok)cout<<"YES";
  else cout<<"NO";
}