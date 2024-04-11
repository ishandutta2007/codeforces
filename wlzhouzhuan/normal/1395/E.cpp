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
auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937 rng(SEED);
const int N=200005;
vector<pii>adj[N];
ull hsh[N],B,all,can[N][10];
int n,m,k,ans;
void dfs(int u,ull hshs){
  if(u==k+1){
    if(hshs==all)ans++;
    return;
  }
  for(register int i=0;i<u;i++){
    dfs(u+1,hshs+can[u][i]);
  }
}
int main(){
  n=read(),m=read(),k=read();
  hsh[0]=1,B=rng();
  for(register int i=1;i<=n;i++)hsh[i]=hsh[i-1]*B,all+=hsh[i];
  for(register int i=1;i<=m;i++){
    int u=read(),v=read(),w=read();
    adj[u].pb({w,v});
  }
  for(register int i=1;i<=n;i++){
    sort(adj[i].begin(),adj[i].end());
    int out=adj[i].size();
    for(register int j=0;j<out;j++){
      can[out][j]+=hsh[adj[i][j].sec];
    }
  }
  dfs(1,0);
  printf("%d\n",ans);
  return 0;
}