#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define rep(i,l,r) for(rint i=l;i<=r;i++)
#define per(i,l,r) for(rint i=l;i>=r;i--)
#define ll long long
#define ull long long
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
mt19937_64 rng(SEED);
const int N=1005;
ll pw[N],light[N],sta[300005];
int cntt[300005];
unordered_map<ll,int>Map;
int l[N],n,s,d;
int id[300005];
int main(){
  n=read(),s=read(),d=read();
  for(int i=1;i<=n;i++)pw[i]=rng();
  for(int i=1;i<=s;i++){
    l[i]=read();
    rep(j,1,l[i]){
      int _=read();
      light[i]^=pw[_];
    }
  }
  int half=s>>1,oth=s-half;
  rep(i,0,(1<<oth)-1)id[i]=i;
  sort(id,id+(1<<oth),[&](int i,int j){
    return __builtin_popcount(i)<__builtin_popcount(j);
  });
  rep(x,0,(1<<oth)-1){
    int i=id[x];
    ll res=0;
    int cnt=0;
    rep(j,0,oth-1){
      if(i>>j&1){
        cnt++;
        res^=light[half+j+1];
      }
    }
    //printf("oth %llu\n",res);
    if(!Map.count(res))Map[res]=cnt;
  }
  rep(i,0,(1<<half)-1){
    ll res=0;
    rep(j,0,half-1){
      if(i>>j&1){
        cntt[i]++;
        res^=light[j+1];
      }
    }
    sta[i]=res;
    //printf("sta[%d]=%llu\n",i,sta[i]); 
  }
  while(d--){
    int x=read();
    ll curr=0;
    while(x--){
      int _=read();
      curr^=pw[_];
    }
    //printf("curr=%llu\n",curr);
    int ans=1e9;
    rep(i,0,(1<<half)-1){
      if(Map.count(curr^sta[i])){
        ans=min(ans,cntt[i]+Map[curr^sta[i]]);
      }
    }
    if(ans==1e9)ans=-1;
    printf("%d\n",ans);
  }
}