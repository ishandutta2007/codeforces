#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;
string s;
int f[N][2];
int main(){
  cin>>s;
  int n=s.length();
  for(int i=1;i<=n;i++) f[i][s[i-1]-'a']=1;
  for(int i=1;i<=n+1;i++)
    for(int j=0;j<=1;j++) f[i][j]+=f[i-1][j];
  int ans=0;
  for(int st=0;st<=n;st++)
    for(int en=st+1;en<=n+1;en++) ans=max(ans,f[st][0]+f[n][0]-f[en-1][0]+f[en-1][1]-f[st][1]);
  cout<<ans;
}