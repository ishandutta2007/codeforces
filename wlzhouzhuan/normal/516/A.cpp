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
const int N=20;
vector<int>ans;
char s[N];
int n;
int main(){
  scanf("%d%s",&n,s+1);
  for(int i=1;i<=n;i++){
    s[i]-='0';
    if(s[i]<=1)continue;
    if(s[i]==2||s[i]==3||s[i]==5||s[i]==7)ans.pb(s[i]);
    else if(s[i]==4)ans.pb(3),ans.pb(2),ans.pb(2);
    else if(s[i]==6)ans.pb(5),ans.pb(3);
    else if(s[i]==8)ans.pb(7),ans.pb(2),ans.pb(2),ans.pb(2);
    else ans.pb(7),ans.pb(3),ans.pb(3),ans.pb(2);
  }
  sort(ans.begin(),ans.end(),greater<int>());
  for(auto v:ans)printf("%d",v);
  puts("");
}