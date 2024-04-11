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
ll inf=1e10;
ll a[5],x;
int main(){
  cin>>a[1]>>a[2]>>a[3];
  cout<<"First"<<'\n';
  cout<<inf<<'\n';
  cin>>x;
  a[x]+=inf;
  ll adds=3*a[x]-a[1]-a[2]-a[3];
  cout<<adds<<'\n';
  cin>>x;
  a[x]+=adds;
  sort(a+1,a+4);
  cout<<(a[2]-a[1])<<'\n';
  cin>>x;
  return 0;
}