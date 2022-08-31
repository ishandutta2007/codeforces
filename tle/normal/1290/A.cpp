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
#define SZ 2333333
int n,m,k,a[SZ];
bool ok(int x,bool vb=0) {
    int bad_ppl=max(m-1-k,0),
    ex=m-1-bad_ppl;
//    cerr<<bad_ppl<<","<<ex<<"\n";
    for(int s=0;s<=ex;++s) {
        bool bad=0;
        for(int i=0;i<=bad_ppl;++i) {
            int bg=i+1,ed=n-(bad_ppl-i);
//            cerr<<bg<<","<<ed<<"?\n";
            // either a[bg+s]
            // or a[ed-(ex-s)]
            if(a[bg+s]>=x||a[ed-(ex-s)]>=x);
            else {bad=1; break;}
        }
        if(!bad) {
//        cerr<<"goo"<<s<<"\n";
        return 1;
        }
    }
    return 0;
    //left: [0,bad_ppl]+
}
void sol() {
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    /*
    cerr<<ok(2)<<"\n";
    return;
    */
    int l=0,r=1e9+1;
    while(l<r) {
        int m=(l+r+1)>>1;
        if(ok(m)) {
//            cerr<<"ok"<<m<<"\n";
            l=m;
        }
        else r=m-1;
    }
    cout<<l<<"\n";
//    cerr<<ok(2,1)<<"\n";
}
int main() {
    #ifdef ONLINE_JUDGE
    cin.tie(0);
    ios::sync_with_stdio(false);
    #endif
    int T; cin>>T; while(T--)
    sol();
}