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

const int N=505;
int dp[N],from[N],inf;
int n,k;
int main() {
  memset(dp,0x3f,sizeof(dp)),inf=0x3f3f3f3f,dp[0]=0;
  scanf("%d%d",&n,&k);
  queue<int>q;q.push(0);
  while(!q.empty()){
    int i=q.front();q.pop();
//    printf("dp[%d]=%d\n",i,dp[i]);
    for(int jb=0;jb<=i&&jb<=k;jb++){
      if(k-jb>n-i)continue;
//      printf("jiba=%d\n",jb);
      int to=i-jb+(k-jb);
//      printf("to=%d\n",to);
      if(dp[to]>dp[i]+1)dp[to]=dp[i]+1,from[to]=i,q.push(to);
    }
//    printf("dp[%d]=%d\n",i,dp[i]);
  }
  if(dp[n]==inf)return puts("-1"),fflush(stdout),0;
  vector<int>stk;
  for(int i=n;i;i=from[i])stk.pb(i);
  stk.pb(0),reverse(stk.begin(),stk.end());
  vector<int>k1,k2;
  int ans=0;
  for(int i=1;i<=n;i++)k1.pb(i);
  for(int i=1;i<SZ(stk);i++){
    int jb=(stk[i-1]+k-stk[i])/2;
    assert(jb>=0);
    printf("? ");
    vector<int>tmp;
    for(int j=1;j<=jb;j++)printf("%d ",k2.back()),tmp.pb(k2.back()),k2.pop_back();
    for(int j=1;j<=k-jb;j++)printf("%d ",k1.back()),k2.pb(k1.back()),k1.pop_back();
    while(SZ(tmp))k1.pb(tmp.back()),tmp.pop_back();
    puts(""),fflush(stdout);
    int x;scanf("%d",&x);ans^=x;
  }
  printf("! %d\n",ans),fflush(stdout);
  return 0;
}