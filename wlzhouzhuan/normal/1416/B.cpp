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
const int N=100005;
struct node{
  int i,j,x;
};
int a[N],n;
int main(){
  int T=read();
  while(T--){
    n=read();
    ll sum=0;
    rep(i,1,n)a[i]=read(),sum+=a[i];
    if(sum%n!=0){
      puts("-1");continue;
    }
    vector<node>ans;
    rep(i,2,n){
      if(a[i]%i==0){
        int dlt=a[i]/i;
        ans.pb({i,1,dlt});
        a[i]-=dlt*i,a[1]+=dlt*i;
      }else{
        int need=i-a[i]%i;
        ans.pb({1,i,need});
        a[i]+=need,a[1]-=need;
        i--;
      }
    }
    sum/=n;
    rep(i,2,n){
      ans.pb({1,i,sum});
    }
    printf("%d\n",ans.size());
    for(auto v:ans)printf("%d %d %d\n",v.i,v.j,v.x);
  }
  return 0;
}