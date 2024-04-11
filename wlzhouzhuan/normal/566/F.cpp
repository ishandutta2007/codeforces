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
const int N=1e6+5;
struct Edge{
  int to,nxt;
}edge[15000001];
int head[N],tot;
void add(int u,int v){
  //cerr<<"add "<<u<<' '<<v<<'\n';
  edge[++tot]={v,head[u]};
  head[u]=tot;
}
int dp[N],a[N],n;

int main(){
  for(register int i=1;i<=1000000;i++){
    for(register int j=i;j<=1000000;j+=i)add(j,i);
  }
  n=read();
  for(int i=1;i<=n;i++)a[i]=read();
  sort(a+1,a+n+1);
  int cnt=1;
  for(int i=1;i<=n;i++){
    if(a[i]==a[i+1]){
      cnt++;continue;
    }
    int cur=0;
    for(register int _=head[a[i]];_;_=edge[_].nxt){
      int j=edge[_].to;
      cur=max(cur,dp[j]);
    }
    dp[a[i]]=cur+cnt;
    cnt=1; 
  }
  printf("%d\n",*max_element(dp+1,dp+N));
  return 0;
}