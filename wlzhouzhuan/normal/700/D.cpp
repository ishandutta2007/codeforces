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
const int N=100005;
int be[N];
int a[N],n,m,q;
struct Q{
  int l,r,id;
  friend bool operator < (const Q &a,const Q &b){
    if(be[a.l]!=be[b.l])return a.l<b.l;
    else if(be[a.l]&1)return a.r<b.r;
    else return a.r>b.r;
  }
}qry[N];
vector<int>v; 
int f[N],cnt[N];
ll ANS[N];
void add(int x){
  f[cnt[x]]--;
  cnt[x]++;
  f[cnt[x]]++;
} 
void del(int x){
  f[cnt[x]]--;
  cnt[x]--;
  f[cnt[x]]++;
}
int tmp[N];
ll solve(){
  priority_queue<ll,vector<ll>,greater<ll>>pq;
  for(auto item:v){
    if(cnt[item]>m){
      pq.push(cnt[item]);
    }
  }
  rep(i,1,m)tmp[i]=f[i];
  int j=0;
  ll ans=0;
  rep(i,1,m)if(tmp[i]){
    if(j){
      if(i+j>m)pq.push(i+j);
      else tmp[i+j]++;
      tmp[i]--;
      ans+=i+j,j=0;
    }
    if(tmp[i]&1)tmp[i]--,j=i;
    if(i+i>m){
      rep(j,1,tmp[i]/2)pq.push(i+i);
    }else{
      tmp[i+i]+=tmp[i]/2;
    }
    ans+=1ll*tmp[i]*i;
  }
  if(j)pq.push(j);
  while(pq.size()>=2){
    ll x=pq.top();pq.pop();
    x+=pq.top();pq.pop();
    ans+=x,pq.push(x);
  }
  return ans;
}
int main(){
  n=read(),m=sqrt(n);
  memset(cnt,0,sizeof(cnt));
  rep(i,1,n){
    a[i]=read(),cnt[a[i]]++;
    be[i]=(i-1)/m+1;
  }
  rep(i,1,100000){
    if(cnt[i]>m)
      v.push_back(i);
  }
  memset(cnt,0,sizeof(cnt));
  q=read();
  rep(i,1,q)qry[i].l=read(),qry[i].r=read(),qry[i].id=i;
  sort(qry+1,qry+q+1);
  int l=1,r=0;
  rep(i,1,q){
    while(l>qry[i].l)l--,add(a[l]);
    while(r<qry[i].r)r++,add(a[r]);
    while(l<qry[i].l)del(a[l]),l++;
    while(r>qry[i].r)del(a[r]),r--;
    ANS[qry[i].id]=solve();
  }
  rep(i,1,q)printf("%lld\n",ANS[i]);
  return 0; 
}