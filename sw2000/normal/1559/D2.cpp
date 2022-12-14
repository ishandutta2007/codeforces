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
const int N=1e5+10,M=5000+10;
const int mod = 998244353;

int n,m[2];
set<int>s[2][N];
int father[2][N];
int ff(int o,int a){return father[o][a]==a?a:father[o][a]=ff(o,father[o][a]);}
void he(int o,int a,int b){
    int fa=ff(o,a),fb=ff(o,b);
    if(fa>fb)swap(fa,fb);
    father[o][fb]=fa;
    if(s[o][fa].size()<s[o][fb].size())swap(s[o][fa],s[o][fb]);
    for(auto i:s[o][fb])s[o][fa].insert(i);
    s[o][fb].clear();
}
int main() {
    freopen("A.in","r",stdin);
    I(n,m[0],m[1]);
    for(int i=1;i<=n;i++){
        father[0][i]=father[1][i]=i;
        s[0][i].insert(i);
        s[1][i].insert(i);
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<m[i];j++){
            int a,b;I(a,b);
            he(i,a,b);
        }
    }
    vector<pii>ans;
    set<int>a,b;
    for(int i=2;i<=n;i++){
        if(!s[0][1].count(i)&&!s[1][1].count(i)){
            he(0,1,i);
            he(1,1,i);
            ans.push_back({1,i});
        }
    }
    for(int i=2;i<=n;i++){
        if(!s[0][1].count(i)&&s[1][1].count(i))a.insert(i);
        else if(!s[1][1].count(i)&&s[0][1].count(i))b.insert(i);
    }

    while(!a.empty()&&!b.empty()){
        int aa=*a.begin(),bb=*b.begin();
        for(auto i:s[0][aa])a.erase(i);
        for(auto i:s[1][bb])b.erase(i);
        he(0,aa,bb);
        he(1,aa,bb);
        ans.push_back({aa,bb});
    }

    O(ans.size(),'\n');
    for(auto i:ans)O(i.fi,' ',i.se,'\n');
}