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
int main(){
  int n;
  cin>>n;
  char s[100];
  sprintf(s,"%X",n);
  int ans=0;
  for(int i=0;i<strlen(s);i++){
    if(s[i]=='0'||s[i]=='4'||s[i]=='6'||s[i]=='9'||s[i]=='A'||s[i]=='D')ans++;
    else if(s[i]=='8'||s[i]=='B')ans+=2; 
  }
  cout<<ans<<'\n';
}