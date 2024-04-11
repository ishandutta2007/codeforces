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
int main(){
  int T=read();
  while(T--){
    int n=read();
    multiset<int>s;
    rep(i,1,n)s.insert(i);
    vector<pii>pr;
    rep(i,1,n-1){
      auto it1=s.end();it1--;int x=*it1;s.erase(it1);
      auto it2=s.end();it2--;int y=*it2;s.erase(it2);
      pr.push_back({x,y});
      s.insert((x+y+1)/2);
    }
    printf("%d\n",*s.begin());
    for(auto v:pr)printf("%d %d\n",v.fir,v.sec);
  }
  return 0;
}