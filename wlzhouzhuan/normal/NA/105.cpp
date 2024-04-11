// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N=100005;
int n;
vector<int>adj[N];
int dp[N];
void dfs1(int u,int fa){
  vector<int>tmp;
  for(auto v:adj[u]){
    if(v==fa)continue;
    dfs1(v,u);
    tmp.pb(dp[v]);
  }
  sort(tmp.begin(),tmp.end(),greater<int>());
  if(!SZ(tmp))dp[u]=1;// 
  if(fa){
    for(int i=0;i<SZ(tmp);i++)ckmax(dp[u],tmp[i]+i);
  }else{
    for(int i=1;i<SZ(tmp);i++)ckmax(dp[u],tmp[i]+i-1);
    if(SZ(tmp)>=1)dp[u]+=tmp[0];
  }
}
int ans;
void dfs2(int u,int fa,int fadp){
  vector<pii>tmp;
  if(fa)tmp.pb({fadp,fa});
  for(auto v:adj[u]){
    if(v==fa)continue;
    tmp.pb({dp[v],v});
  }
  sort(tmp.begin(),tmp.end(),greater<pii>());
  
  int res=0;
  for(int i=1;i<SZ(tmp);i++)ckmax(res,tmp[i].fir+i-1);
  if(SZ(tmp)>=1)res+=tmp[0].fir;
  ckmax(ans,res);
//  printf("loc=%d,ans=%d\n",u,res);

  int len=SZ(tmp);
  vector<int>pre(len),suf(len);
  for(int i=0;i<len;i++){
    if(i)pre[i]=pre[i-1];
    ckmax(pre[i],tmp[i].fir+i);
  }
  for(int i=len-1;i>=0;i--){
    if(i<len-1)suf[i]=suf[i+1]+1;
    ckmax(suf[i],tmp[i].fir);
  }
  for(int i=0;i<len;i++){
    if(tmp[i].sec==fa)continue;
    int v=tmp[i].sec;
    dfs2(v,u,max((i>0?pre[i-1]:1),(i<len-1?suf[i+1]+i:1)));
  }
}
int query(int u){
  printf("? %d\n",u),fflush(stdout); 
  int x;scanf("%d",&x);return x;
}
int solve(int u,int fa){
  vector<pii> tmp;
  for(auto v:adj[u]){
    if(v==fa)continue;
    tmp.pb({dp[v],v});
  }
  sort(tmp.begin(),tmp.end(),greater<pii>());
  if(!SZ(tmp))return query(u);
  if(fa){
    for(auto it:tmp){
      int v=it.sec,kind=solve(v,u);
      if(kind!=u)return kind;
    }
    return u;
  }else{
    vector<int>qwq;//ans
    for(auto it:tmp){
      int v=it.sec,kind=solve(v,u);
      if(kind!=u){
        qwq.pb(kind);
        if(SZ(qwq)==2)break;
      }
    }
    while(SZ(qwq)!=2)qwq.pb(u);
    printf("! %d %d\n",qwq[0],qwq[1]),fflush(stdout); 
    return 0;//!
  }
}
int main(){
  scanf("%d",&n);
  if(n==1){
    puts("0"),fflush(stdout);
    int f;scanf("%d",&f);
    puts("! 1 1"),fflush(stdout);
    return 0; 
  }
  for(int i=1;i<n;i++){
    int u=read(),v=read();
    adj[u].pb(v),adj[v].pb(u);
  }
  dfs1(1,0),dfs2(1,0,0);
  printf("%d\n",ans),fflush(stdout);
  int f;scanf("%d",&f);
  dfs1(f,0),solve(f,0);
  return 0;
}