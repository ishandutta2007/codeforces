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
int a[N],b[N];
int n,m,p,q;

int main(){
  n=read(),m=read();
  p=read();while(p--)a[read()]=1;
  q=read();while(q--)b[read()]=1;
  for(int i=1;i<=2*n*m;i++){
    int t=a[i%n]|b[i%m];
    a[i%n]=b[i%m]=t;
  }
  int ok=1;
  for(int i=0;i<n;i++)ok&=a[i];
  for(int i=0;i<m;i++)ok&=b[i];
  puts(ok?"Yes":"No");
}