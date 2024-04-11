#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=1005;
const int D=55;
const ll mod=1e9+7;

char s[N],a[N],b[N];
int len,n;

int ed[N*D],ch[N*D][10],fail[N*D],tot;
void getFail(){
  queue<int>q;
  for(int i=0;i<10;i++){
    if(ch[0][i])q.push(ch[0][i]);
  }
  while(!q.empty()){
    int u=q.front();q.pop();
    for(int i=0;i<10;i++){
      if(ch[u][i]){
        fail[ch[u][i]]=ch[fail[u]][i];
        q.push(ch[u][i]);
      }else
        ch[u][i]=ch[fail[u]][i];
    }
  }
}

// f[i][node][0/1]iACnode/ 
ll p[D][2],f[D][N*D][2];
ll solve(char *a){
  memset(f,0,sizeof(f));
  p[n+1][0]=p[n+1][1]=1;
  for(int i=1;i<=n;i++)a[i]-='0';
  for(int i=n;i>=1;i--){
    p[i][0]=10ll*p[i+1][0]%mod;
    p[i][1]=(1ll*a[i]*p[i+1][0]+p[i+1][1])%mod;
  }
  f[0][0][1]=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<=tot;j++){
      if(!ed[j]){
        for(int k=0;k<10;k++){
          int u=ch[j][k];
          f[i+1][u][0]=(f[i+1][u][0]+f[i][j][0])%mod;
          if(k<a[i+1])f[i+1][u][0]=(f[i+1][u][0]+f[i][j][1])%mod;
          if(k==a[i+1])f[i+1][u][1]=(f[i+1][u][1]+f[i][j][1])%mod;
        }
      }
    }
  }
  ll ans=0ll;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=tot;j++){
      if(ed[j])
        ans=(ans+f[i][j][0]*p[i+1][0]+f[i][j][1]*p[i+1][1])%mod;
    }
  }
  return ans;
}

int main(){
  scanf("%s%s%s",s+1,a+1,b+1);
  len=strlen(s+1),n=strlen(a+1);
  int d=n/2;
  for(int i=1;i<=len;i++)s[i]-='0';
  for(int i=1;i+d-1<=len;i++){
    int u=0;
    for(int j=i;j<=i+d-1;j++){
      if(!ch[u][s[j]])ch[u][s[j]]=++tot;
      u=ch[u][s[j]];
    }
    ed[u]=1;
  }
  getFail();
  
  int _=n;
  while(a[_]=='0')a[_--]='9';    
  a[_]--;
  printf("%lld\n",(solve(b)-solve(a)+mod)%mod);
  return 0;
}