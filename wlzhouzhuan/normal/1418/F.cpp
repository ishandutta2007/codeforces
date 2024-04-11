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
#define int long long
const int N=5000005;
struct Edge{
  int to,nxt;
}edge[N];
int head[N],tot;
void add(int u,int v){
  edge[++tot]={v,head[u]};
  head[u]=tot;
}
set<int>s;
int cnt[N],n,m,l,r;
signed main(){
  cin>>n>>m>>l>>r;
  for(int i=1;i<=200000;i++){
    for(int j=i;j<=200000;j+=i){
      add(j,i);
    } 
  }
  for(int i=1,lstL=m+1,lstR=m;i<=n;i++){
    int L=(l-1)/i+1,R=r/i;
    while(lstL>L){
      lstL--;
      for(register int k=head[lstL];k;k=edge[k].nxt){
        int v=edge[k].to;
        if(cnt[v]++==0)s.insert(v);
      }
    }
    while(lstR>R){
      for(register int k=head[lstR];k;k=edge[k].nxt){
        int v=edge[k].to;
        if(--cnt[v]==0)s.erase(v);
      }
      lstR--;
    }
    int ok=0;
    for(register int k=head[i];k;k=edge[k].nxt){
      int d=edge[k].to,t=i/d;
      auto it=s.upper_bound(t);
      if(it!=s.end()&&*it<=n/d){
        int tmp=((L-1)/(*it)+1)*(*it);
        ok=1;
        //printf("d=%d,t=%d\n",d,t);
        printf("%lld %lld %lld %lld\n",i,tmp,d*(*it),i*tmp/(d*(*it)));
        break;
      }
    }
    if(!ok)puts("-1");
  }
  return 0;
}