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

int ar[N];
void solve(){
    int n;I(n);
    for(int i=1;i<=n;i++)I(ar[i]);
    bool f=0;
    for(int i=1;i<=n;i++){
        if(!f){
            if(ar[i]){
                O(n+1,' ');
                f=1;
            }
        }
        O(i,' ');
    }
    if(!f)O(n+1);
}
int main() {
    freopen("A.in","r",stdin);
    int _;I(_);
    while(_--){
        solve(),O('\n');
    }
}