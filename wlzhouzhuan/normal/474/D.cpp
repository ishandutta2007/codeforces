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
const int N=100005;
const int mod=1e9+7;
int f[N],T,l,r,n,k;
int sum[N];
int main(){
  scanf("%d%d",&T,&k);
  n=N-5;
  f[0]=sum[0]=1;
  for(int i=1;i<=n;i++){
    if(i<k)f[i]=f[i-1];
    else f[i]=(f[i-1]+f[i-k])%mod;
    sum[i]=(sum[i-1]+f[i])%mod;
  }
  while(T--){
    int l,r;
    scanf("%d%d",&l,&r);
    printf("%d\n",(sum[r]-sum[--l]+mod)%mod);
  }
  return 0;
}