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
const int N=305;
int a[N][N],b[N][N];
int n,m;
void solve(){
  n=read(),m=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      a[i][j]=read();
    }
  }
  b[1][1]=b[1][m]=b[n][1]=b[n][m]=2;
  for(int i=2;i<m;i++)b[1][i]=b[n][i]=3;
  for(int i=2;i<n;i++)b[i][1]=b[i][m]=3;
  for(int i=2;i<n;i++){
    for(int j=2;j<m;j++){
      b[i][j]=4;
    } 
  } 
  int ok=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(b[i][j]<a[i][j]){
        ok=0;
      } 
    }
  }
  if(!ok)puts("NO");
  else{
    puts("YES");
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        printf("%d ",b[i][j]);
      }
      puts("");
    }
  }
}
int main(){
  int T=read();
  while(T--)solve();
  return 0;
}