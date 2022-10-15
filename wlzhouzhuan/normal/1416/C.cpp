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
vector<int>a;
ll dp[35][2];
int n;
void solve(vector<int>a,int bit){
  if(bit==-1||a.size()==0)return;
  vector<int>low,high;
  int cnt0=0,cnt1=0;
  for(auto v:a){
    if(v>>bit&1){
      dp[bit][1]+=cnt0;
      cnt1++;
      high.pb(v);
    }else{
      dp[bit][0]+=cnt1;
      cnt0++;
      low.pb(v);
    }
  }
  solve(low,bit-1),solve(high,bit-1);
}
int main(){
  n=read();
  rep(i,1,n)a.push_back(read());
  solve(a,30);
  ll ans=0,num=0;
  per(i,30,0){
    //printf("dp[%d][0]=%d,dp[%d][1]=%d\n",i,dp[i][0],i,dp[i][1]);
    if(dp[i][0]<=dp[i][1]){
      ans+=dp[i][0];
    }else{
      ans+=dp[i][1];
      num^=1ll<<i;
    }
  }
  printf("%lld %lld\n",ans,num);
}