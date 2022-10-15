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
struct node{
  int val,id;
  friend bool operator < (const node&x,const node&y){
    if(x.val!=y.val)return x.val<y.val;
    else return x.id<y.id;
  }
}t[N];
vector<pii>ans;
int a[N],pos[N],n;
int main(){
  n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    t[i]={a[i],i};
  }
  sort(t+1,t+n+1);
  for(int i=1;i<=n;i++)a[t[i].id]=i;
  for(int i=1;i<=n;i++)pos[a[i]]=i;
  for(int i=n;i>=1;i--){
    for(int j=a[i]+1;j<=i;j++){
      int p1=pos[j],p2=i;
      ans.pb({p1,p2});
      pos[a[p1]]=p2,pos[a[p2]]=p1;
      swap(a[p1],a[p2]);
    }
  }
  printf("%d\n",ans.size());
  for(auto v:ans)printf("%d %d\n",v.fir,v.sec);
  return 0;
}