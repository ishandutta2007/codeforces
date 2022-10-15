#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define rep(i,l,r) for(rint i=l;i<=r;i++)
#define per(i,l,r) for(rint i=l;i>=r;i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define fir first
#define sec second
#define mset(s,t) memset(s,t,sizeof(s))
template<typename T1,typename T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1}; 
const int N=205;
char str[N][N];
int n,vis[N][N];
bool bfs(int num){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      vis[i][j]=0;
    }
  }
  queue<pii>q;
  q.push({1,1});
  vis[1][1]=1;
  while(!q.empty()){
    pii u=q.front();q.pop();
    int x=u.fir,y=u.sec;
    for(int d=0;d<4;d++){
      int xx=x+dx[d],yy=y+dy[d];
      if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&!vis[xx][yy]){
        if(str[xx][yy]==(num^1))continue;
        vis[xx][yy]=1;
        q.push({xx,yy});
      }
    }
  }
  return vis[n][n];
}
void solve(){
  for(int x=0;x<2;x++){
    for(int y=0;y<2;y++){
      for(int z=0;z<2;z++){
        for(int t=0;t<2;t++){
          if(x)str[1][2]^=1;
          if(y)str[2][1]^=1;
          if(z)str[n-1][n]^=1;
          if(t)str[n][n-1]^=1;
          if(!bfs(0)&&!bfs(1)){
            int num=x+y+z+t;
            if(num<=2){
              printf("%d\n",num);
              if(x)printf("1 2\n");
              if(y)printf("2 1\n");
              if(z)printf("%d %d\n",n-1,n);
              if(t)printf("%d %d\n",n,n-1);
              return;
            }
          }
          if(x)str[1][2]^=1;
          if(y)str[2][1]^=1;
          if(z)str[n-1][n]^=1;
          if(t)str[n][n-1]^=1;
        }
      }
    }
  }
}
int main(){
  int T=read();
  while(T--){
    n=read();
    for(int i=1;i<=n;i++){
      scanf("%s",str[i]+1);
      for(int j=1;j<=n;j++){
        if(i==1&&j==1)continue;
        if(i==n&&j==n)continue;
        str[i][j]-='0';
      } 
    }
    solve();
  }
}