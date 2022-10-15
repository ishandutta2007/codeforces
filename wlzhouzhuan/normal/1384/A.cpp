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
const int N=105;
char s[N][N];
int a[N],n;
char mex(char x){
  if(x=='a')return 'b';
  else return 'a';
}
int main(){
  int T=read();
  while(T--){
    n=read();
    rep(i,1,n)a[i]=read();
    rep(i,1,n+1){
      if(i==1){
        rep(j,1,200){
          s[i][j]='a';
          putchar('a');
        }
      }else{
        rep(j,1,200){
          if(j<=a[i-1])putchar(s[i][j]=s[i-1][j]);
          else putchar(s[i][j]=mex(s[i-1][j]));
        }
      }
      putchar('\n');
    }
  }
  return 0;
}