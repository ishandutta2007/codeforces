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
const int N=105;
ll f[N][N],g[N][N],a[N][N];
int n,m,k;
int main(){
  scanf("%d%d%d",&n,&m,&k);
  memset(f,-0x3f,sizeof(f)),f[0][0]=0;
  for(int i=1;i<=n;i++){
    memset(g,-0x3f,sizeof(g)),g[0][0]=0;
    for(int j=1;j<=m;j++){
      a[i][j]=read();
      for(int num=m/2;num>=1;num--){
        for(int mod=0;mod<k;mod++){
          ckmax(g[num][mod],g[num-1][(mod-a[i][j]%k+k)%k]+a[i][j]);
        }
      }
    }
    for(int mod=0;mod<k;mod++){
      for(int cur=0;cur<k;cur++){
        for(int num=0;num<=m/2;num++){
          ckmax(f[i][mod],f[i-1][(mod-cur%k+k)%k]+g[num][cur]);
        }
      }
    }
  }
  printf("%lld\n",f[n][0]);
  return 0;
}