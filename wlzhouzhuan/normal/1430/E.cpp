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
const int N=200005;
char str[N];
deque<int>qwq[555];
int n;
struct Bit{
  int c[N];
  void add(int x,int dlt){
    while(x<=n){
      c[x]+=dlt,x+=x&-x;
    }
  }
  int qry(int x){
    int ret=0;
    while(x>0){
      ret+=c[x],x^=x&-x;
    }
    return ret;
  }
}bit;
ll ans=0;
int main(){
  scanf("%d",&n);
  scanf("%s",str+1);
  n=strlen(str+1);
  for(int i=1;i<=n;i++){
    qwq[str[i]].push_back(i);
  }
  for(int i=n;i>=1;i--){
    int id=qwq[str[i]].front();qwq[str[i]].pop_front();
    ans+=bit.qry(n)-bit.qry(id);
    bit.add(id,1);
  }
  printf("%lld\n",ans);
  return 0;
}