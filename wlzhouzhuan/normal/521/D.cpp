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
vector<pair<double,int>>d[N],all;
int a[N],maxx[N],id[N];
int n,q,m;
int main(){
  n=read(),q=read(),m=read();
  for(int i=1;i<=n;i++)a[i]=read(),maxx[i]=a[i];
  for(int i=1;i<=q;i++){
    int opt=read(),u=read(),w=read();
    if(opt==1){
      if(maxx[u]<w)maxx[u]=w,id[u]=i;
    }else if(opt==2){
      d[u].pb({w,i});
    }else{
      all.pb({w,i+q});
    }
  }
  for(int i=1;i<=n;i++){
    if(maxx[i]>a[i]){
      d[i].pb({maxx[i]-a[i],id[i]-q});
    }
    sort(d[i].begin(),d[i].end(),[&](pair<double,int>a,pair<double,int>b){
      return a.first>b.first;
    });
    double sum=a[i];
    for(auto j:d[i]){
      all.pb({(sum+j.first)/sum,j.second});
      sum+=j.first;
    }
  }
  sort(all.begin(),all.end(),[&](pair<double,int>a,pair<double,int>b){
    return a.first>b.first;
  });
  //for(auto v:all)printf("%.2lf %d\n",v.first,v.second); 
  int ans=min((int)all.size(),m);
  printf("%d\n",ans);
  sort(all.begin(),all.begin()+ans,[&](pair<double,int>a,pair<double,int>b){
    return a.second<b.second;
  });
  for(int i=0;i<ans;i++)printf("%d ",(all[i].second+2*q-1)%q+1);
  puts("");
  return 0;
}