#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
char gc(void){
    const int S=3e7;
    static char buf[S],*s=buf,*t=buf;
    if (s==t) t=buf+fread(s=buf,1,S,stdin);
    if (s==t) return EOF;
    return *s++;
}
void read(char &c){while(c=gc(),c==' '||c=='\n');}
void read(string &s){
    char c;
    while(c=gc(),c!=' '&&c!='\n'&&c!=EOF)s+=c;
}
void read(char *s){
    char c;
    while(c=gc(),c!=' '&&c!='\n'&&c!=EOF)*s=c,s++;
}
template<class T>void read(T&ret) {
	char c;
	if(c=gc(),c==EOF)return;
	while(c!='-'&&c!='.'&&(c<'0'||c>'9'))c=gc();
	int sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=gc(),c>='0'&&c<='9')ret=ret*10+(c-'0');
	if(c==' '||c=='\n') {
		ret*=sgn;
		return;
	}
	T bit=0.1;
	while(c=gc(),c>='0'&&c<='9')ret+=(c-'0')*bit,bit/=10;
	ret*=sgn;
}
void I(){};
template<class T,class... A>void I(T &a,A&... x){read(a);I(x...);}
void write(char x){putchar(x);}
void write(string x){cout<<x;}
void write(const char *x){printf(x);}
void write(double x){printf("%.10lf",x);}
void write(long double x){printf("%.10Lf",x);}
template<class T>void write(T x) {
    if(x<0)putchar('-'),x*=-1;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
void O(){};
template<class T,class... A>void O(T a,A... x){write(a);O(x...);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a, b, c)
#define K(a...)
#endif
typedef __int128_t il;
typedef unsigned long long ul;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<int>vl;
const double PI=acos(-1);
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=2e5+10;
const int mod=998244353;

namespace SWNB{
    const int mod = 998244353;
    typedef long long ll;
    const int maxn = 400010;
    ll powmod(ll a,ll b){
        ll ans=1;
        while(b){if(b&1) ans=ans*a%mod;a=a*a%mod;b>>=1;}
        return ans;
    }
    ll fac[maxn],ifac[maxn];
    void init(){
        fac[0]=1;ifac[0]=1;
        for(int i=1;i<maxn;i++) {fac[i]=fac[i-1]*i%mod;ifac[i]=powmod(fac[i],mod-2);}
    }
    ll C(int n,int m){
        if(n<m||m<0) return 0;
        if(n==m||m==0) return 1;
        return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
    }
    ll solve(int n,int m){
        if(fac[0]==0) init();
        if(n<m) return 0;
        int x=2*n-m-1,y=n;
        return C(x,y);
    }
}
int n,m;
int x[N],y[N];
int sum[N<<2];
ll rev[N<<1],fac[N<<1];
ll pm(ll a,ll b){
    ll ret=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ret=ret*a%mod;
    return ret;
}
ll C(int a,int b){
    return fac[a]*pm(rev[b],mod-2)%mod*pm(rev[a-b],mod-2)%mod;
}
void build(int o=1,int l=1,int r=2e5){
    if(l==r){
        sum[o]=1;
        return;
    }
    build(lo,l,mid);
    build(ro,mid+1,r);
    sum[o]=sum[lo]+sum[ro];
}
int fd(int p,int o=1,int l=1,int r=2e5){
    if(l==r){
        return l;
    }
    if(sum[lo]>=p)return fd(p,lo,l,mid);
    else return fd(p-sum[lo],ro,mid+1,r);
}
void add(int p,int v,int o=1,int l=1,int r=2e5){
    if(l==r){
        sum[o]+=v;
        return;
    }
    if(p<=mid)add(p,v,lo,l,mid);
    else add(p,v,ro,mid+1,r);
    sum[o]=sum[lo]+sum[ro];
}
int solve(){
    I(n,m);
    vi v;
    for(int i=0;i<m;i++){
        I(x[i],y[i]);
    }
    set<int>s;
    int c=0;
    for(int i=m-1;~i;i--){
        int p=fd(y[i]);
        if(!s.count(p+1)){
            c++;
        }
        s.insert(p);
        add(p,-1);
    }
    for(auto i:s)add(i,1);

    return SWNB::solve(n,c);
}
int main() {
    freopen("A.in","r",stdin);
    build();
    fac[0]=1;
    for(int i=1;i<N*2;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    rev[N*2-1]=pm(fac[N*2-1],mod-2);
    for(int i=N*2-2;~i;i--){
        rev[i]=rev[i+1]*(i+1)%mod;
    }
    int _;I(_);
    while(_--){
        O(solve(),'\n');
    }
}