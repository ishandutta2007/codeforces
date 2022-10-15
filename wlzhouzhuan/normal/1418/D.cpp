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
int n,q;
set<int>s;
multiset<int>fuck;
void ins(int x){
  auto pre=s.lower_bound(x),suf=s.upper_bound(x);
  int ok1=0,ok2=0;
  if(pre!=s.begin())pre--,ok1=1;
  if(suf!=s.end())ok2=1;
  if(ok1&&ok2)fuck.erase(fuck.find(*suf-*pre));
  if(ok1)fuck.insert(x-*pre);
  if(ok2)fuck.insert(*suf-x);
  s.insert(x);
}
void del(int x){
  auto pre=s.lower_bound(x),suf=s.upper_bound(x);
  int ok1=0,ok2=0;
  if(pre!=s.begin())pre--,ok1=1;
  if(suf!=s.end())ok2=1;
  if(ok1)fuck.erase(fuck.find(x-*pre));
  if(ok2)fuck.erase(fuck.find(*suf-x));
  if(ok1&&ok2)fuck.insert(*suf-*pre);
  s.erase(x);
}
int getans(){
  if(s.empty())return 0;
  else return *(--s.end())-*s.begin()-*(--fuck.end());
}
int main(){
  fuck.insert(0);
  n=read(),q=read();
  for(int i=1;i<=n;i++){
    int x=read();
    ins(x);
  }
  //for(auto v:s)printf("%d ",v);puts("");
  //for(auto v:fuck)printf("%d ",v);puts("");
  printf("%d\n",getans());
  while(q--){
    int opt=read(),x=read();
    if(opt==1)ins(x);
    else del(x);
    printf("%d\n",getans());
  }
  return 0;
}