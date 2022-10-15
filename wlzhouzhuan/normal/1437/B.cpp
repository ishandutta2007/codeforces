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
const int N=100005;
char s[N];
int n;
int main(){
  int T=read();
  while(T--){
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)s[i]^='0';
    int qwq=0,qaq=0;
    for(int i=2;i<=n;i++){
      if(s[i]==s[i-1])qwq++;
    }
//    printf("qwq=%d,qaq=%d\n",qwq,qaq);
    qwq++;
    printf("%d\n",qwq>>1);
  }
}