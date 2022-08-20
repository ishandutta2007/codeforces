#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned us;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define mod 998244353
#define maxn 1200005
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}

#define all(x) (x).begin(),(x).end()

const int MOD=998244353; // change this!!
ll qp(ll a,ll b) {
	ll ans=1; a%=MOD;
	while(b)
	{
		if(b&1) ans=ans*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return ans;
}

// modint start
union mi {
	us w;
	mi() {w=0;}
	mi(us u) {w=u;}
	mi(int u) {u%=MOD; w=u+((u<0)?MOD:0);}
	explicit operator us() const {return w;}
	explicit operator int() const {return w;}
};
mi operator + (const mi& a,const mi& b)
{return mi{a.w+b.w-((a.w+b.w>=MOD)?(MOD):0)};}
mi operator - (const mi& a,const mi& b)
{return mi{a.w-b.w+((a.w<b.w)?(MOD):0)};}
mi operator * (const mi& a,const mi& b)
{return mi{us((ull)a.w*b.w%MOD)};}
mi operator / (const mi& a,const mi& b)
{return mi{us((ull)a.w*qp(b.w,MOD-2)%MOD)};}
mi inv(const mi& a){return mi{us(qp(a.w,MOD-2))};}
bool operator == (const mi& a,const mi& b) {return a.w==b.w;}
bool operator != (const mi& a,const mi& b) {return a.w!=b.w;}
mi& operator += (mi& a,const mi& b)
{a.w=a.w+b.w-((a.w+b.w>=MOD)?MOD:0); return a;}
mi& operator -= (mi& a,const mi& b)
{a.w=a.w-b.w+((a.w<b.w)?MOD:0); return a;}
mi& operator *= (mi& a,const mi& b) {a=a*b; return a;}
mi& operator /= (mi& a,const mi& b) {a=a/b; return a;}
mi operator - (const mi& a) {return mi{a.w?(MOD-a.w):0};}
mi& operator ++ (mi& a) {a.w=a.w+1-((a.w+1>=MOD)?MOD:0); return a;}
mi& operator -- (mi& a) {a.w=a.w-1+(a.w?0:MOD); return a;}
void cp(mi*t,const mi*s,int K) {
	if(s) memcpy(t,s,sizeof(mi)*K);
	else memset(t,0,sizeof(mi)*K);
}
void cp(mi*t,mi s,int K) {
	if(s.w==0) memset(t,0,sizeof(mi)*K);
	else for(int i=0;i<K;++i) t[i]=s;
}
mi qp(mi a,ll b) {
	mi x=1;
	while(b) {
		if(b&1) x=x*a;
		a=a*a; b>>=1;
	}
	return x;
}
string to_string(mi f) {return to_string((int)f);}
string pretty_guess(mi x,int max_dem=1000) {
	string s=to_string((int)x);
	auto upd=[&](string v) {
		if(v.size()<s.size()) s=v;
	};
	upd("-"+to_string((int)(-x)));
	for(int i=1;i<=max_dem;++i) {
		mi w=x*i;
		upd(to_string((int)w)+"/"+to_string(i));
		upd("-"+to_string((int)(-w))+"/"+to_string(i));
	}
	return s;
}
ostream& operator << (ostream& os,const mi& m) {
	os<<m.w; return os;
}
istream& operator >> (istream& is,mi& m) {
	int x; is>>x; m=x; return is;
}
// modint end


// debug macros start
template <class T1, class T2>ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
return os << '(' << p.first << ", " << p.second << ')';}
template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
class = enable_if_t<!is_same<T, string>::value>>ostream &operator<<(ostream &os, const T &c) {os << '[';
for (auto it = c.begin(); it != c.end(); ++it)os << &", "[2 * (it == c.begin())] << *it;return os << ']';}
template <class T1,class T2>ostream &operator<<(ostream &os, const map<T1,T2> &c) {os << '{';
bool first=1;for(const auto& a:c) os<<(first?"":", ")<<a.fi<<": "<<a.se, first=0;return os<<"}";}
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_0(_CALL, ...)
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                             \
  _NTH_ARG(dummy, ##__VA_ARGS__, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1, _FE_0)     \
  (MACRO, ##__VA_ARGS__)
#define outff(x) #x " = " << x << "; "
#define DBG(...)                                                              \
  cerr << "Line " << __LINE__ << ": " FOR_EACH_MACRO(outff, __VA_ARGS__) << "\n"
// debug macros end
vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])

#define SZ 400099
int T,n,k,x[SZ],d[SZ]; Edg
pii nr[SZ];
void d1(int x,int fa=0) {
    for esb(x,e,b) if(b!=fa) {
        nr[b]=min(nr[b],mp(nr[x].fi+1,nr[x].se));
        d1(b,x);
    }
}
void d2(int x,int fa=0) {
    for esb(x,e,b) if(b!=fa) {
        d2(b,x);
        nr[x]=min(nr[x],mp(nr[b].fi+1,nr[b].se));
    }
}
void sol() {
    cin>>n>>k;M=0;
    for(int i=1;i<=n;++i)fst[i]=d[i]=0,nr[i]=pii(1e9,1e9);
    nr[1]=pii(0,1);
    for(int i=1;i<=k;++i)cin>>x[i],nr[x[i]]=pii(0,0);
    for(int i=1,a,b;i<n;++i)
        cin>>a>>b,adde(a,b),++d[a],++d[b];
    d2(1); d1(1);
    for(int i=2;i<=n;++i) if(d[i]<=1&&nr[i].se) {
        puts("YES");
        return;
    }
    puts("NO");
}
int main() {
    #ifdef ONLINE_JUDGE
    cin.tie(0);
    ios::sync_with_stdio(0);
    #endif
    cin>>T;
    while(T--) sol();
}