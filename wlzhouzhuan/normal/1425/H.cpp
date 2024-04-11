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
int main(){
  int T=read();
  while(T--){
    int A=read(),B=read(),C=read(),D=read();
    if(((A+B)&1)&&(A||D))printf("Ya ");
    else printf("Tidak ");
    if(((A+B)&1)&&(B||C))printf("Ya ");
    else printf("Tidak ");
    if((A+B)%2==0&&(B||C))printf("Ya ");
    else printf("Tidak ");
    if((A+B)%2==0&&(A||D))printf("Ya ");
    else printf("Tidak ");
    puts("");
  }
  return 0;
}
/* 
int dp[155];
int main(){
  dp[1]=1;
  for(int i=2;i<=100;i++){
    if(i%2==0)dp[i]=max(i-1-dp[i-1]+1,i/2-dp[i/2]+i/2);
    else dp[i]=i-1-dp[i-1]+1;
    printf("dp[%d]=%d\n",i,dp[i]);
  }
  
}
*/