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
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;


const double PI = acos(-1.0);
const int maxn = 400005;
const int mod = 1009;
struct cp
{
    double x,y;
    cp(double a=0,double b=0){x=a,y=b;}
    inline cp operator + (cp &a) {return cp{x+a.x,y+a.y};}
    inline cp operator - (cp &a) {return cp{x-a.x,y-a.y};}
    inline cp operator * (cp &a) {return cp{x*a.x-y*a.y,x*a.y+y*a.x};}
    inline void operator /= (double a) {x/=a,y/=a;}
    inline void operator += (cp &a) {x+=a.x,y+=a.y;}
    inline cp conj() {return cp(x,-y);}
}w[maxn], w_inv[maxn], A[maxn],B[maxn];
void init(int n) {for(int i=0;i<n;++i) w[i] = cp(cos(2*PI/n*i), sin(2*PI/n*i)), w_inv[i] = w[i].conj();}
void fft(cp *a, int n, int f=0) {
    cp *ww;if(f) ww=w;else ww=w_inv;
    for(int i=0,j=0;i<n;++i) {
        if(i>j) swap(a[i],a[j]);
        for(int l=n>>1;(j^=l)<l;l>>=1);
    }
    for(int l=2;l<=n;l<<=1) {
        int m=l/2;
        for (cp *p=a;p!=a+n;p+=l) {
            for (int i=0;i<m;++i) {
                cp t = ww[n/l*i]*p[m+i];
                p[m+i]=p[i]-t,p[i]+=t;
            }
        }
    }
    if(f) for(int i=0;i<n;++i) a[i]/=n;
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
    int m=a.size()+b.size(),len=1;for(;len<=m;len<<=1);
    for(int i=0;i<a.size();++i) A[i]=a[i];
    for(int i=0;i<b.size();++i) B[i]=b[i];
    for(int i=a.size();i<=len;++i) A[i]=0;
    for(int i=b.size();i<=len;++i) B[i]=0;
    init(len);
    fft(A,len);fft(B,len);
    for(int i=0;i<len;++i) A[i]=A[i]*B[i];
    fft(A,len,-1);
    a.resize(len);
    for(int i=0;i<len;++i) a[i]=(ll)(A[i].x+0.5)%mod;
    while(len>0 && !a[len-1]) --len;
    a.resize(len);
}
priority_queue<pii,vector<pii>,greater<pii>> q;
vector<ll> v[maxn];
int cnt[maxn];
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) {
        int x;
        cin>>x;
        cnt[x]++;
    }
    int tp=0;
    for(int i=1;i<=m;++i) {
        if(!cnt[i]) continue;
        v[++tp].resize(cnt[i]+1,1);
        q.push({v[tp].size(), tp});
    }
    while(q.size()>1) {
        pii p1=q.top();q.pop();
        pii p2=q.top();q.pop();
        mul(v[p1.second],v[p2.second]);
        q.push({v[p1.second].size(),p1.second});
    }
    auto &res = v[q.top().second];
    if(res.size() < k) cout << 0 << endl;
    else cout << res[k] << endl;
}