#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
template <int _P>struct Z{
    static constexpr int P=_P;
private :
    int v;
public :
    Z() : v(0){}
    Z(ll _v){v=_v%P;if(v<0)v+=P;}
    explicit operator int() const {return v;}
    explicit operator ll() const {return v;}
    explicit operator bool() const {return v>0;}
    bool operator == (const Z &o) const {return v==o.v;}
    bool operator != (const Z &o) const {return v!=o.v;}
    Z operator - () const {return Z(v?P-v:0);}
    Z operator + () const {return *this;}
    Z & operator ++ (){v++;if(v==P)v=0;return *this;}
    Z & operator -- (){if(v==0)v=P;v--;return *this;}
    Z operator ++ (int){Z r=*this;++*this;return r;}
    Z operator -- (int){Z r=*this;--*this;return r;}
    Z & operator += (const Z &o){v+=o.v;if(v>=P)v-=P;return *this;}
    Z operator + (const Z & o)const{return Z(*this)+=o;}
    Z & operator -= (const Z & o){v-=o.v;if(v<0)v+=P;return *this;}
    Z operator - (const Z &o)const {return Z(*this)-=o;}
    Z & operator *=(const Z & o){v=(int)(((ll)v)*o.v%P);return *this;}
    Z operator * (const Z & o)const {return Z(*this)*=o;}
    Z & operator /= (const Z & o){return (*this)*=o.Inv();}
    Z operator / (const Z & o)const{return Z(*this)/=o;}
    Z operator + (const ll &o)const {return (*this)+(Z)o;}
    Z operator - (const ll &o)const {return (*this)-(Z)o;}
    Z operator * (const ll &o)const {return (*this)*(Z)o;}
    Z operator ^ (ll o)const{Z r=1,t=v;while(o){if(o&1)r*=t;t*=t;o>>=1;}return r;}
    Z operator ~ (){return (*this)^(P-2);}
    Z Inv() const{return (*this)^(P-2);}
};
char gc(void){
    const int S=3e7;
    static char buf[S],*s=buf,*t=buf;
    if (s==t) t=buf+fread(s=buf,1,S,stdin);
    if (s==t) return EOF;
    return *s++;
}
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
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<int>vl;
const double PI=acos(-1);
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=5e5+10,M=5000+10;
const int mod = 1e9+7;

int n,m1,m2;
pii e1[N],e2[N];
int f1[N],f2[N];
int ff1(int a){return f1[a]==a?a:f1[a]=ff1(f1[a]);}
int ff2(int a){return f2[a]==a?a:f2[a]=ff2(f2[a]);}
void solve(){
    I(n,m1,m2);
    iota(f1,f1+1+n,0);
    iota(f2,f2+1+n,0);
    for(int i=0;i<m1;i++)I(e1[i].fi,e1[i].se);
    for(int i=0;i<m2;i++)I(e2[i].fi,e2[i].se);
    for(int i=0;i<m1;i++){
        int fa=ff1(e1[i].fi),fb=ff1(e1[i].se);
        f1[fa]=fb;
    }
    for(int i=0;i<m2;i++){
        int fa=ff2(e2[i].fi),fb=ff2(e2[i].se);
        f2[fa]=fb;
    }
    vector<pii>ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int fa=ff1(i),fb=ff1(j);
            int fc=ff2(i),fd=ff2(j);
            if(fa!=fb&&fc!=fd){
                f1[fa]=fb;
                f2[fc]=fd;
                ans.push_back({i,j});
            }
        }
    }
    O(ans.size(),'\n');
    for(auto i:ans)O(i.fi,' ',i.se,'\n');
}
int main() {
    freopen("A.in","r",stdin);
    solve();
}