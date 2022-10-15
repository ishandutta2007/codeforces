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
const int N=100015;
vector<pii>kind[N];
int sz;
typedef struct _bitset {
    ll data[70];
    _bitset() { memset(data, 0, sizeof(data)); }
    friend _bitset operator|(const _bitset &a, const _bitset &b) {
        _bitset c;
        for (register int i = 0; i <= sz; i++) c.data[i] = a.data[i] | b.data[i];
        return (c);
    }
    friend _bitset operator&(const _bitset &a, const _bitset &b) {
        _bitset c;
        for (register int i = 0; i <= sz; i++) c.data[i] = a.data[i] & b.data[i];
        return (c);
    }
    inline int test(int b) { return ((data[b / 64] & (1ull << (b & 63))) != 0); }
    inline void set(int b) { data[b / 64] |= (1ull << (b & 63)); }
} bitfuck;
bitfuck f[N];
int n,k,q,len;
int main(){
  n=read(),k=read(),q=read();
  sz = (1 << k) / 64 + 1;
  rep(i,0,k-1){
    rep(j,0,n-1){
      int x=read();
      kind[j].pb(make_pair(x,i));
    }
    rep(j,0,(1<<k)-1){
      if(j>>i&1)f[i].set(j);
    }
  }
  rep(i,0,n-1){
    sort(kind[i].begin(),kind[i].end(),greater<pii>());
//    printf("kind[%d] = ",i);
//    for(auto v:kind[i])printf("(%d, %d), ",v.fir,v.sec);
//    puts("");
  }
  int len=k;
  while(q--){
    int opt=read(),x=read(),y=read();
    x--,y--;
    if(opt==1){
      f[len]=f[x]|f[y];
      len++;
    }else if(opt==2){
      f[len]=f[x]&f[y];
      len++;
    }else{
      int s=0;
      for(auto v:kind[y]){
        s|=1<<v.sec;
        if(f[x].test(s)){
          printf("%d\n",v.fir);
          break;
        }
      }
    }
  }
  return 0;
}