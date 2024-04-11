#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int maxn = 500005;
const int mod = 1e9+7;
int a[maxn][2];
int par[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
int merge(int u,int v) {
    int x=find(u),y=find(v);
    if(x==y) return 0;
    par[x]=y;
    return 1;
}
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n=read(),m=read();
    for(int i=1;i<=n;++i) {
        int k=read();
        if(k==2) {
            a[i][0]=read();
            a[i][1]=read();
        } else {
            a[i][0]=read();
        }
    }
    for(int i=1;i<=m;++i) par[i]=i;
    vector<int> v;
    for(int i=1;i<=n;++i) {
        if(merge(a[i][0],a[i][1])) {
            v.push_back(i);
        }
    }
    printf("%lld %d\n",fpow(2,v.size()),(int)v.size());
    for(int i:v) printf("%d ",i);
    puts("");
}