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
const int N=25;
ull n;
int a[N],len,s,S;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%llu%d",&n,&S);
    ull tmpn=n;
    len=0,s=0;
    while(n>0){
      a[++len]=n%10,s+=n%10; 
      n/=10;
    }
    if(s<=S){
      puts("0");continue;
    }
    a[++len]=0;
    reverse(a+1,a+len+1);
    ull ans=1e19;
    for(int i=1;i<=len;i++){
      if(a[i]<9){
        int sum=0;
        for(int j=1;j<=i;j++)sum+=a[j];
        sum++;
        if(sum>S)continue;
        ull ret=0;
        for(int j=1;j<=i;j++)ret=10ull*ret+a[j];
        ret++;
        for(int j=i+1;j<=len;j++)ret=10ull*ret;
        ans=min(ans,ret);
      }
    }
    printf("%llu\n",ans-tmpn);
  }
  return 0;
}