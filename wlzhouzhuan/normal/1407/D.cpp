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
const int N=300005;
stack<int>st1,st2;
int a[N],dp[N],n;
int main(){
  n=read();
  for(int i=1;i<=n;i++)a[i]=read();
  dp[1]=0,st1.push(1),st2.push(1);
  for(int i=2;i<=n;i++){
    dp[i]=dp[i-1]+1;
    while(!st1.empty()&&a[st1.top()]<=a[i]){
      int x=a[st1.top()];
      st1.pop();
      if(x<a[i]&&!st1.empty())dp[i]=min(dp[i],dp[st1.top()]+1);
    }
    while(!st2.empty()&&a[st2.top()]>=a[i]){
      int x=a[st2.top()];
      st2.pop();
      if(x>a[i]&&!st2.empty())dp[i]=min(dp[i],dp[st2.top()]+1);
    }
    st1.push(i),st2.push(i);
  }
  printf("%d\n",dp[n]);
  return 0;
}