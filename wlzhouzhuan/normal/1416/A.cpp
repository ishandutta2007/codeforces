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
const int N=300005;
const int inf=1e9;
vector<int>id[N];
int a[N],len[N],n;
int main(){
  int T=read();
  while(T--){
    n=read();
    rep(i,1,n)id[i].clear();
    rep(i,1,n){
      a[i]=read();
      id[a[i]].push_back(i);
    }
    rep(i,0,n)len[i]=inf;
    rep(i,1,n){
      if(!id[i].size())continue;
      int maxx=0,len2=id[i].size();
      maxx=id[i][0];
      rep(j,1,len2-1)ckmax(maxx,id[i][j]-id[i][j-1]);
      ckmax(maxx,n+1-id[i][len2-1]);
      ckmin(len[maxx],i);
    }
    rep(i,1,n)ckmin(len[i],len[i-1]);
    rep(i,1,n){
      if(len[i]==inf)printf("-1 ");
      else printf("%d ",len[i]);
    }
    puts("");
  }
  return 0;
}