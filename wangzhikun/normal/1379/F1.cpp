#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>string to_string(pair<A, B> p);template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);string to_string(const string& s) {  return '"' + s + '"';}string to_string(const char* s) {  return to_string((string) s);}string to_string(bool b) {  return (b ? "true" : "false");}string to_string(vector<bool> v) {  bool first = true;  string res = "{";  for (int i = 0; i < static_cast<int>(v.size()); i++) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(v[i]);  }  res += "}";  return res;}template <size_t N>string to_string(bitset<N> v) {  string res = "";  for (size_t i = 0; i < N; i++) {    res += static_cast<char>('0' + v[i]);  }  return res;}template <typename A>string to_string(A v) {  bool first = true;  string res = "{";  for (const auto &x : v) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(x);  }  res += "}";  return res;}template <typename A, typename B>string to_string(pair<A, B> p) {  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}void debug_out() { cerr << endl; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {  cerr << " " << to_string(H);  debug_out(T...);}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define set0(x) memset(x,0,sizeof(x))
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
    read(first);
    read(args...);
}

vector<pii> Ops[800080];

int n,m,q,x,y;

map<pii,int> Mp;

void add_op(int id,int l,int r,int ql,int qr,pii Op){
    if(ql<=l && r<=qr){
        Ops[id].PB(Op);
        return;
    }
    int mid = (l+r)/2;
    if(ql<=mid)add_op(id*2,l,mid,ql,qr,Op);
    if(qr>mid)add_op(id*2+1,mid+1,r,ql,qr,Op);
}

int ok = 1;

set<pii> CIA;

set<int> high[200020],low[200020];

struct MaxTree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	MaxTree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
}MxT(200020);

struct MinTree {
	typedef int T;
	static constexpr T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	MinTree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
}MiT(200020);

void enact(pii A){
    if(!ok) return;
    CIA.insert(A);
    int x = (A.F+1)/2,y = 200000-(A.S+1)/2;
    if(A.F%2){
        high[x].insert(y);
        MxT.update(x,*high[x].rbegin());
        int c = MiT.query(x,200020);
        if(c<=y)ok = 0;
    }else{
        low[x].insert(y);
        MiT.update(x,*low[x].begin());
        int c = MxT.query(1,x+1);
        if(c>=y)ok = 0;
    }
}

void deenact(pii A){
    if(!CIA.count(A)) return;
    CIA.erase(A);
    int x = (A.F+1)/2,y = 200000-(A.S+1)/2;
    if(A.F%2){
        high[x].erase(y);
        MxT.update(x,*high[x].rbegin());
    }else{
        low[x].erase(y);
        MiT.update(x,*low[x].begin());
    }
}

void walk(int id,int l,int r){
    for(auto ct:Ops[id]) enact(ct);
    if(!ok){
        for(int i=l;i<=r;i++)cout<<"NO\n";
    }else{
        if(l == r)cout<<"YES\n";
        else{
            int mid = (l+r)/2;
            walk(id*2,l,mid);
            walk(id*2+1,mid+1,r);
        }
    }
    ok = 1;
    for(auto ct:Ops[id]) deenact(ct);
}

int main() {
    read(n,m,q);
    for(int i=1;i<=n;i++){
        high[i].insert(INT_MIN);
        low[i].insert(INT_MAX);
    }
    for(int i=1;i<=q;i++){
        read(x,y);
        if(Mp.count(MP(x,y))){
            add_op(1,1,q,Mp[MP(x,y)],i-1,MP(x,y));
            Mp.erase(MP(x,y));
        }else{
            Mp[MP(x,y)] = i;
        }
    }
    for(auto ct:Mp){
        add_op(1,1,q,ct.S,q,ct.F);
    }
    walk(1,1,q);
    return 0;
}