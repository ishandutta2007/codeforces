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
const int N=1005;
vector<int>ans;
int a[N],n;
int cnt[N];
int mex(){
  for(int i=0;i<=n;i++)cnt[i]=0;
  for(int i=1;i<=n;i++)cnt[a[i]]=1;
  for(int i=0;i<=n;i++){
    if(!cnt[i])return i;
  }  
}
void solve(){
  ans.clear();
  n=read();
  for(int i=1;i<=n;i++)a[i]=read();
  for(int i=1;i<=n;i++){
    if(a[i]==i-1)continue;
    while(1){
      int t=mex();
      if(t==n){
        for(int j=i+1;j<=n;j++)if(a[j]!=j-1){
          ans.pb(j);
          a[j]=n;
          break;
        }
      }else{
        ans.pb(t+1);
        a[t+1]=t;
      }
      if(t==i-1)break;
    }
  }
  printf("%d\n",ans.size());
  for(auto v:ans)printf("%d ",v);
  puts("");
}
int main(){
  int T=read();
  while(T--)solve();
  return 0;
}