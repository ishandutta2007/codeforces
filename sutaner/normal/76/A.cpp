#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxr], *p1, *p2;
    template<class T> void read_signed(T& x){
        char ch = gc(); x = 0; bool f = 1;
        while (!isdigit(ch) && ch != '-') ch = gc();
        if (ch == '-') f = 0, ch = gc();
        while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
        x = (f) ? x : -x;
    }
    template<class T, class... Args> void read_signed(T& x, Args&... args){
        read_signed(x), read_signed(args...);
    }
    template<class T> void read_unsigned(T& x){
        char ch = gc(); x = 0;
        while (!isdigit(ch)) ch = gc(); 
        while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = gc(); 
    }
    template<class T, class... Args> void read_unsigned(T& x, Args&... args){
        read_unsigned(x), read_unsigned(args...);
    }
    #define isletter(ch) ('a' <= ch && ch <= 'z')
    int read_string(char* s){
        char ch = gc(); int l = 0;
        while (!isletter(ch)) ch = gc();
        while (isletter(ch)) s[l++] = ch, ch = gc();
        s[l] = '\0'; return l;
    }
}using namespace Fast_Read; 

int _num[200];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

#define read read_unsigned
#define reads read_string 
#define writes puts

#define maxn 500020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 

int n, m, G, S;
struct edge{
	int x, y, w, z;
	edge(int x, int y, int w, int z) : x(x), y(y), w(w), z(z){}
	edge(){}
	bool operator < (const edge b) const{
		return w == b.w ? z == b.z ? y == b.y ? x < b.x : y < b.y : z < b.z : w < b.w;
	}
}e[maxn];
bool cmp(const edge a, const edge b) {
	return a.z < b.z;
}
multiset<edge> s;

int ufs[maxn], cnt;
int find_root(int x){
	return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}
bool merge(int x, int y){
	x = find_root(x), y = find_root(y);
	if (x == y) return false;
	ufs[x] = y;
	cnt--;
	return true;
}

edge lis[maxn]; int cs = 0;

int main(){
	int x, y, z, w;
	read(n, m, G, S);
	rep(i, 1, m) read(x, y, z, w), e[i] = edge(x, y, z, w);
	sort(e + 1, e + 1 + m, cmp);
	ll mi = -1;
	rep(i, 1, m) {	
		rep(j, 1, n) ufs[j] = j; cnt = n;
		s.insert(e[i]);
		ll d = 0;
		for (auto it: s){
			if (merge(it.x, it.y)) d = it.w;
			else lis[++cs] = it;
		}
		rep(i, 1, cs) s.erase(s.lower_bound(lis[i])); cs = 0;
		if (cnt == 1) {
			ll v = 1ll * e[i].z * S + 1ll * d * G;
			mi = (mi == -1) ? v : min(mi, v);
		}
	}
	write(mi);
	return 0;
}