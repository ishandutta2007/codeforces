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
#define int long long
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
int n,m,b,g,d,x[100005],y[100005];
ll c[200005];
vector<int>V[200005],W[200005];
struct node
{
    ll x,y,z;
};
vector<node>buc;
map<int,int>mp;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
void exgcd(int a,int b,int &x,int &y){if(!b){x=1;y=0;return;}exgcd(b,a%b,y,x);y-=(a/b)*x;}
bool cmp(node x,node y){return x.z<y.z;}
ll solve(vector<int>v,vector<int>w)
{
    if(w.size()==m)return -1;
    if(v.size()==0&&w.size()==0)return -2;
    ll ans=0;
    mp.clear();
    for(auto i:w)mp[i]=i;
    for(auto i:v)
        if(mp.find(i%m)==mp.end())mp[i%m]=i;
        else mp[i%m]=min(mp[i%m],i);
    buc.clear();
    int t1,t2;
    for(auto i:mp)
    {
        buc.push_back(node{i.first,i.second,0});
        exgcd(n,m,t1,t2);
        long long t=1ll*t1*i.first;
        t+=1ll*m*ceil(1.0*(1-t)/m);
        if(t==m)t-=m;
        buc[buc.size()-1].z=t;
    }
    sort(buc.begin(),buc.end(),cmp);
    for(int i=1;i<buc.size();i++)
        ans=max(ans,buc[i-1].y+1ll*(buc[i].z-buc[i-1].z-1)*n);
    if(buc.size()>1)ans=max(ans,buc[buc.size()-1].y+1ll*(m-buc[buc.size()-1].z+buc[0].z-1)*n);
    else ans=1ll*(m-1)*n+buc[0].y;
    return ans;
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    scanf("%lld",&b);
    for(int i=1;i<=b;i++)scanf("%lld",&x[i]);
    scanf("%lld",&g);
    for(int i=1;i<=g;i++)scanf("%lld",&y[i]);
    d=gcd(n,m);
    if(d>b+g){puts("-1");return 0;}
    for(int i=1;i<=b;i++)V[x[i]%d].push_back(x[i]/d);
    for(int i=1;i<=g;i++)W[y[i]%d].push_back(y[i]/d);
    n/=d,m/=d;
    ll ans=0;
    for(int i=0;i<d;i++)
    {
        ll t=solve(V[i],W[i]);
        if(t==-2){puts("-1");return 0;}
        if(t==-1)continue;
        ans=max(ans,t*d+i);
    }
    swap(n,m);
    for(int i=0;i<d;i++)
    {
        ll t=solve(W[i],V[i]);
        if(t==-1)continue;
        ans=max(ans,t*d+i);
    }
    printf("%lld\n",ans);
    return 0;
}