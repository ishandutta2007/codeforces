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
mt19937_64 rng(SEED);
const int N=500005;
unordered_map<ll,int>Map;
deque<int>q[N];
int num[N],a[N],n;
ll hsh[N],pre[N];

int main(){
  n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    hsh[i]=rng();
  }
  Map[0]++,pre[0]=0;
  int cur=0;
  ll hshs=0ll,ans=0ll;
  for(int i=1;i<=n;i++){
    int x=a[i],bef=num[x];
    num[x]=(num[x]+1)%3;
    hshs+=1ll*(num[x]-bef)*hsh[x];
    pre[i]=hshs;
    q[x].push_back(i);
    while(q[x].size()>3){
      while(cur<q[x].front()){
        Map[pre[cur]]--;
        cur++;
      }
      q[x].pop_front();
    } 
    //printf("i = %d, hsh = %lld, adds = %d\n", i, hshs, Map[hshs]);
    ans+=Map[hshs];
    Map[hshs]++;
  }
  printf("%lld\n",ans);
  return 0;
}