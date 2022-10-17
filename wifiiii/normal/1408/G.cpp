#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int maxn = 400005;
const int mod = 998244353;
ll fpow(ll a,ll b) {
    a%=mod;ll ret=1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}
ll w[maxn];
void ntt(vector<ll> &a, int f=0) {
    int n=a.size();
    for(ll i=0,j=0;i<n;++i) {
        if(i>j) swap(a[i],a[j]);
        for(int l=n>>1;(j^=l)<l;l>>=1);
    }
    w[0]=1;
    for(int l=2;l<=n;l<<=1) {
        ll g=fpow(3,(mod-1)/l);
        if(f) g=fpow(g,mod-2);
        for(int j=(l>>1);j>=0;j-=2) w[j]=w[j>>1];
        for(int j=1;j<(l>>1);j+=2) w[j]=w[j-1]*g%mod;
        int m=l/2;
        for(int j=0;j!=n;j+=l) {
            for(int i=0;i<m;++i) {
                ll tmp=w[i]*a[j+i+m]%mod;
                a[j+i+m]=(a[i+j]-tmp+mod)%mod,a[i+j]=(a[i+j]+tmp)%mod;
            }
        }
    }
    if(f) {
        ll inv=fpow(n,mod-2);
        for(int i=0;i<n;++i) a[i]=a[i]*inv%mod;
    }
}
void mul(vector<ll>&a,vector<ll>&b) {
    if(max(a.size(),b.size())<128) {
        int sza=a.size(),szb=b.size(),len=sza+szb-1;
        vector<ll> ret(len);
        for(int i=0;i<sza;i++)
            for(int j=0;j<szb;j++)
                ret[i+j]+=a[i]*b[j]%mod;
        a.resize(len);
        for(int i=0;i<len;++i) a[i]=ret[i]%mod;
        while(len>0 && !a[len-1]) --len;
        a.resize(len);
        return;
    }
    int m=a.size()+b.size(),len=1;
    for(;len<=m;len<<=1);
    a.resize(len);b.resize(len);
    ntt(a);ntt(b);
    for(int i=0;i<len;++i) a[i]=a[i]*b[i]%mod;
    ntt(a,-1);
    while(len>0 && !a[len-1]) --len;
    a.resize(len);
}
vector<ll> v[maxn];

//while(q.size()>1)
//{
//    pii p1=q.top();q.pop();
//    pii p2=q.top();q.pop();
//    mul(v[p1.second],v[p2.second]);
//    q.push({v[p1.second].size(),p1.second});
//}

int par[maxn], cnt[maxn], sz[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
struct edge {
    int u,v,w;
    bool operator < (const edge & e) const {
        return w < e.w;
    }
}es[1500005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ii par[i] = i, sz[i] = 1;
    int tp = 0;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            int x;
            cin>>x;
            if(i < j) {
                es[++tp] = {i, j, x};
            }
        }
    }
    for(int i=1;i<=n;++i) v[i].resize(2),v[i][1]=1;
    sort(es+1,es+1+tp);
    for(int i=1;i<=tp;++i) {
        int x=find(es[i].u),y=find(es[i].v);
        if(x == y) {
            cnt[x]++;
        } else {
            if(sz[x] > sz[y]) swap(x, y);
            par[x] = y;
            mul(v[y], v[x]);
            sz[y]+=sz[x];
            cnt[y]+=cnt[x];
            cnt[y]++;
        }
        int szy = sz[y];
        if(cnt[y] == szy*(szy-1)/2) {
            v[y][1]++;
        }
    }
    int rt = find(1);
    v[rt].resize(n+1);
    for(int i=1;i<=n;++i) {
        cout<<v[rt][i]<<" ";
    }
    cout << endl;
}