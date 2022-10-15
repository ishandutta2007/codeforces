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
const int N=500005;
int b[N];
int a[N],n;
bool check(int x){
  for(int i=2,j=1;j<=x;i+=2,j++)b[i]=a[j];
  for(int i=1,j=n-x;j<=n;i+=2,j++)b[i]=a[j];
  for(int i=2;i<=2*x;i+=2){
    if(b[i-1]>b[i]&&b[i]<b[i+1]);
    else return false;
  }
  return true;
}
int main(){
  n=read();
  rep(i,1,n)a[i]=read();
  sort(a+1,a+n+1);
  int l=1,r=(n-1)/2+1,ans=0;
  while(l<r){
    int mid=l+r>>1;
    if(check(mid))ans=mid,l=mid+1;
    else r=mid;
  }
  printf("%d\n",ans);
  int x=ans;
  for(int i=2,j=1;j<=x;i+=2,j++)b[i]=a[j];
  for(int i=1,j=n-x;j<=n;i+=2,j++)b[i]=a[j];
  for(int i=2*x+2,j=x+1;i<=n;i++,j++)b[i]=a[j];
  rep(i,1,n)printf("%d ",b[i]);puts("");
  return 0;
}