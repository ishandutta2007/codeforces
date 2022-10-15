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
const int N=200005;
ll a[N],b[N],sum;
int n,k;
int main(){
  n=read(),k=read();
  rep(i,1,k)a[i]=read(),b[i]=read(),sum+=b[i];
  if(sum>n)puts("-1"),exit(0);
  if(sum<n)puts("1"),exit(0);
  ll res=0;
  rep(i,1,k)res=(res+a[i]*b[i])%n;
  res=(res-1ll*n*(n+1)/2)%n;
  if(res==0)puts("1");
  else puts("-1");
  return 0;
}