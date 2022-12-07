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

int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

#define read read_signed
#define reads read_string 
#define writes puts

#define maxn 600020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n;

namespace Tree1{
	struct edge{
		int next, to;
		edge(int next, int to) : next(next), to(to){}
		edge(){}
	}e[maxn << 1];
	int cnt = 1, h[maxn];
	void Add_Edge(int x, int y) {
		e[++cnt] = edge(h[x], y);
		h[x] = cnt;
		e[++cnt] = edge(h[y], x);
		h[y] = cnt;
	}
	int dfs[maxn], idx = 0, siz[maxn];
	void DFS(int x, int fa){
		siz[x] = 1;
		dfs[x] = ++idx;
		erep(i, x) {
			int op = e[i].to;
			if (op == fa) continue;
			DFS(op, x);
			siz[x] += siz[op];
		} 
	}
	void recover(){
		rep(i, 1, n) h[i] = 0; cnt = 1; idx = 0;
	}
}

namespace Tree2{
	struct edge{
		int next, to;
		edge(int next, int to) : next(next), to(to){}
		edge(){}
	}e[maxn << 1];
	int cnt = 1, h[maxn];
	void Add_Edge(int x, int y) {
		e[++cnt] = edge(h[x], y);
		h[x] = cnt;
		e[++cnt] = edge(h[y], x);
		h[y] = cnt;
	}
	int dfs[maxn], idx = 0, siz[maxn];
	void DFS(int x, int fa){
		siz[x] = 1;
		dfs[x] = ++idx;
		erep(i, x) {
			int op = e[i].to;
			if (op == fa) continue;
			DFS(op, x);
			siz[x] += siz[op];
		} 
	}
	
	pii get_int(int x) {
		return pii(Tree1 :: dfs[x], Tree1 :: dfs[x] + Tree1 :: siz[x] - 1);
	}
	
	set<pii> s;
	set<pii> :: iterator it;
	struct rec{
		pii pre, now;
		rec(pii pre, pii now) : pre(pre), now(now){}
		rec(){}
	}sta[maxn];
	int head = 0, ans = 0;
	void solve(int x, int fa){
		int _head = head;
		pii now = get_int(x);
		if (s.empty()) {
			sta[++head] = rec(pii(-1, -1), now);
			s.insert(now);
		}
		else {
			it = s.lower_bound(pii(now.fi, -1));
			if (it != s.end() && it -> fi == now.fi) {
				if (it -> fi <= now.fi && now.se <= it -> se){
					sta[++head] = rec(*it, now);
					s.erase(it);
					s.insert(now);
				}
				else goto done;
			}
			else {
				if (it != s.end() && now.fi <= it -> fi && it -> se <= now.se) goto done; 
				else { 
					if (it == s.begin()) {
						sta[++head] = rec(pii(-1, -1), now);
						s.insert(now);
					}
					else {
						it--;
						if (it -> fi <= now.fi && now.se <= it -> se){
							sta[++head] = rec(*it, now);
							s.erase(it);
							s.insert(now);
						}
						else {
							sta[++head] = rec(pii(-1, -1), now);
							s.insert(now);
						}
					}
				}
			}
		}
		done: ans = max(ans, (int)s.size());
		erep(i, x) {
			int op = e[i].to;
			if (op == fa) continue;
			solve(op, x);
		}
		while (head > _head) {
			pii pre = sta[head].pre, now = sta[head].now;
			head--;
			if (pre.fi == -1) {
				s.erase(now);
				continue;
			}
			else {
				s.erase(now);
				s.insert(pre);
			}
		}
	}
	void work(){
		solve(1, -1);
		printf("%d\n", ans);
		
		//assert(s.empty());
	}
	void recover(){
		rep(i, 1, n) h[i] = 0; cnt = 1; idx = 0;
		s.clear();
		head = 0;
		ans = 0;
	}
}

int main(){
	int T, x; read(T);
	while (T--){
		read(n);
		rep(i, 2, n) read(x), Tree2 :: Add_Edge(x, i);
		rep(i, 2, n) read(x), Tree1 :: Add_Edge(x, i);
		Tree1 :: DFS(1, -1), Tree2 :: DFS(1, -1);
		
		Tree2 :: work();
		
		Tree1 :: recover(), Tree2 :: recover();
	}
	return 0;
}