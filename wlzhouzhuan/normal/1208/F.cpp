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
const int N=3000005;

int a[N],mx[N][2],n;
void update(int u,int id){
  if(mx[u][0]<=id)mx[u][1]=mx[u][0],mx[u][0]=id;
  else if(mx[u][1]<=id)mx[u][1]=id;
}
int getans(int w,int id){
  int S=0;
  if(mx[0][1]<=id)return 0;
  per(j,20,0)if(w>>j&1){
    S|=1<<j;
    if(mx[S][1]<id)S^=1<<j;
  }
  return S^a[id];
}
int main(){
  n=read();
  rep(i,1,n){
    a[i]=read();
    update(a[i],i);
  }  
  rep(j,0,20){
    per(i,(1<<21)-1,0){
      if(i>>j&1)continue;
      int qwq=i|1<<j;
      update(i,mx[qwq][0]),update(i,mx[qwq][1]);
    }
  }
  //cerr<<"!\n";
  int ans=0;
  rep(i,1,n){
    ckmax(ans,getans((1<<21)-1-a[i],i));
  }
  printf("%d\n",ans);
  return 0;
}