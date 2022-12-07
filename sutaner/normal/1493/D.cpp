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

#define maxn 500020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 1000000007
#define ll long long int 
int n, q, a[maxn];
int p[maxn], vis[maxn], cp = 0;
void init(){
	srep(i, 2, maxn) {
		if (!vis[i]) p[++cp] = i;
		rep(j, 1, cp) {
			if (i * p[j] >= maxn) break;
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
int power(int x, int y) {
	int ans = 1, con = x;
	while (y) {
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
int getinv(int x) {
	return power(x, M - 2);
}
multiset<int> mi[maxn];
map<int, int> dd[maxn];
void dep(int x, int id) {
	rep(i, 1, cp) {	
		if (1ll * p[i] * p[i] > x) break;	
		if (x % p[i] == 0) {
			
			int res = 0;
			while (x % p[i] == 0) {
				res++;
				x /= p[i];
			}
			mi[i].insert(res);
			dd[id][i] = res;
		}
	}
	if (x > 1) {
		int pos = lower_bound(p + 1, p + 1 + cp, x) - p;
		dd[id][pos] = 1;
		mi[pos].insert(1);
	}
}

/*
int pro(int x, int y, int& ans){
	int _x = x * y, __x = x;
	
	rep(i, 1, cp) {	
		if (1ll * p[i] * p[i] > x) break;
		if (x % p[i] == 0) {
			if (mi[i].size() == n) ans /= power(p[i], *mi[i].begin());
			int res = 0;
			while (x % p[i] == 0) {
				res++;
				x /= p[i];
			}
			mi[i].erase(mi[i].lower_bound(res));
		}
	}
	if (x > 1) {
		int pos = lower_bound(p + 1, p + 1 + cp, x) - p;
		if (mi[pos].size() == n) ans /= power(p[pos], *mi[pos].begin());
		mi[pos].erase(mi[pos].lower_bound(1));
	}
	
	
	x = _x;
	
	
	rep(i, 1, cp) {	
		if (1ll * p[i] * p[i] > x) break;	
		if (x % p[i] == 0) {
			int res = 0;
			while (x % p[i] == 0) {
				res++;
				x /= p[i];
			}
			mi[i].insert(res);
			if (mi[i].size() == n) ans *= power(p[i], *mi[i].begin());
		}  
	}
	if (x > 1) {
		int pos = lower_bound(p + 1, p + 1 + cp, x) - p;
		mi[pos].insert(1);
		if (mi[pos].size() == n) ans *= power(p[pos], *mi[pos].begin());
	}
	
	return ans;
	
	int res = ans;
	
	x = _x;
	rep(i, 1, cp) {	
		if (1ll * p[i] * p[i] > x) break;	
		if (x % p[i] == 0) {
			int res = 0;
			while (x % p[i] == 0) {
				res++;
				x /= p[i];
			}
			mi[i].erase(mi[i].lower_bound(res));
		}  
	}
	if (x > 1) {
		int pos = lower_bound(p + 1, p + 1 + cp, x) - p;
		mi[pos].erase(mi[pos].lower_bound(1)); 
	}
	
	
	x = __x;
	
	rep(i, 1, cp) {	
		if (1ll * p[i] * p[i] > x) break;
		if (x % p[i] == 0) { 
			int res = 0;
			while (x % p[i] == 0) {
				res++;
				x /= p[i];
			}
			mi[i].insert(res);
		}
	}
	if (x > 1) {
		int pos = lower_bound(p + 1, p + 1 + cp, x) - p; 
		mi[pos].insert(1);
	}
	
	return res;
}
*/

void upd(int i, int v, int& ans) {
	if (v == 1) {
		if (mi[i].size() == n) ans = 1ll * ans * power(p[i], *mi[i].begin()) % M;
	}
	else {
		if (mi[i].size() == n) ans = 1ll * ans * getinv(power(p[i], *mi[i].begin())) % M;
	}
}
void pro(int id, int y, int& ans){  
	rep(i, 1, cp) {	
		if (1ll * p[i] * p[i] > y) break;
		if (y % p[i] == 0) {
			upd(i, -1, ans);
			if (dd[id].count(i)) {
				mi[i].erase(mi[i].lower_bound(dd[id][i]));
			}
			int res = 0;
			while (y % p[i] == 0) {
				res++;
				y /= p[i];
			}
			if (dd[id].count(i)) dd[id][i] += res;
			else dd[id][i] = res;
			mi[i].insert(dd[id][i]);
			upd(i, 1, ans);
		}
	}
	if (y > 1) {
		int i = lower_bound(p + 1, p + 1 + cp, y) - p;
		upd(i, -1, ans);
		if (dd[id].count(i)) {
			mi[i].erase(mi[i].lower_bound(dd[id][i]));
		}
		if (dd[id].count(i)) dd[id][i] += 1;
		else dd[id][i] = 1;
		mi[i].insert(dd[id][i]);
		upd(i, 1, ans);
	} 
}

int main(){
	init();
	read(n, q);
	rep(i, 1, n) read(a[i]), dep(a[i], i);
	int ans = 1;
	rep(i, 1, cp) {
		if (mi[i].size() < n) continue;
		else ans *= power(p[i], *mi[i].begin());
	}
	int x, y;
	rep(i, 1, q) {
		read(x, y);
		pro(x, y, ans);
		printf("%d\n", ans);
		//a[x] *= y;
	}
	return 0;
}