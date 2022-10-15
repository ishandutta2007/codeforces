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
int pr[N],len,n;
bool vis[N];
void init(int n){
  for(register int i=2;i<=n;i++){
    if(!vis[i])pr[++len]=i;
    for(register int j=1;j<=len&&pr[j]*i<=n;j++){
      vis[pr[j]*i]=1;
      if(i%pr[j]==0)break;
    }
  }
}
int main(){
  cin>>n;
  init(n);
  int B=sqrt(len);
  int ans=1,sum=n; 
  for(register int i=1;i<=len;i+=B){
    int j=min(len,i+B-1);
    for(register int k=i;k<=j;k++){
      printf("B %d\n",pr[k]);
      fflush(stdout);
      int x=read();
      sum-=x;
    }
    printf("A 1\n");
    fflush(stdout); 
    int y=read();
    if(sum<y){
      sum=y;
      for(register int k=i;k<=j;k++){
        for(register int num=pr[k];num<=n;num*=pr[k]){
          printf("A %d\n",num);
          fflush(stdout);
          int x=read();
          if(x)ans*=pr[k];
          else break;
          if(num>n/pr[k])break;
        }
      }
    }
  }
  printf("C %d\n",ans);
  fflush(stdout);
  return 0;
}