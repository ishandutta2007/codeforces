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
const int mod=998244353;
template<typename T1,typename T2>void add(T1 &a,T2 b){a+=b;if(a>=mod)a-=mod;}
template<typename T1,typename T2>void sub(T1 &a,T2 b){a-=b;if(a<0)a+=mod;}
const int N=1000005;
int x[N],dif[N],n,k,res; 
void solve(){
  n=read(),k=read();
  res=0;
  for(int i=1;i<=n;i++){
    x[i]=read();
    if(i==1){
      dif[++res]=1;continue;
    }
    if(x[i]^x[i-1]){
      if(dif[res]!=k)dif[res]++;
      else dif[++res]=2;
    }
  }
  for(int i=1;i<=res;i++)if(dif[i]>k){
    puts("-1");return;
  } 
  printf("%d\n",res);
}
int main(){
  int T=read();
  while(T--)solve();
  return 0;
}