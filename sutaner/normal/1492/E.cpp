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

#define maxn 400020
#define maxm 
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m; 
vector<int> g[maxn]; 
int cri[maxn];
int cal(int i, int j) {
	int res = 0;
	rep(x, 1, m) {
		if (g[i][x] != g[j][x]) res++;
	}
	return res;
}
int dis[maxn]; 
bool judge(){
	rep(i, 1, n) {
		int res = 0;
		rep(j, 1, m) {
			if (cri[j] != g[i][j]) res++;
		}
		if (res > 2) return false;
	}
	return true;
}
void output(){
	puts("Yes");
	rep(i, 1, m) write(cri[i], ' ');
	exit(0);
}
int lis[5][maxn], cs[5];
int main(){
	int x;
	read(n, m);
	rep(i, 1, n) {
		g[i].pb(-1); rep(j, 1, m) read(x), g[i].pb(x);
	}
	rep(i, 2, n) {
		dis[i] = cal(1, i);
		if (dis[i] > 4) {
			puts("No");
			return 0;
		}
		lis[dis[i]][++cs[dis[i]]] = i;
	}
	if (!cs[4] && !cs[3]) {	
		rep(i, 1, m) cri[i] = g[1][i];
		output();
	}
	if (cs[4]) {
		int other = lis[4][1];
		int err[10]; int ce = 0;
		rep(i, 1, m) {
			if (g[other][i] == g[1][i]) cri[i] = g[1][i];
			else err[++ce] = i;
		}
		srep(i, 0, (1 << 4)) {
			rep(j, 0, 3) {
				int pl = err[j + 1];
				if (i & (1 << j)) cri[pl] = g[1][pl];
				else cri[pl] = g[other][pl];
			}
			if (judge()) output();
		}
		puts("No");
		return 0;
	}
	else {
		int other = lis[3][1];
		int err[10]; int ce = 0;
		rep(i, 1, m) {
			if (g[other][i] == g[1][i]) cri[i] = g[1][i];
			else err[++ce] = i;
		}
		srep(i, 0, (1 << 3)) {
			rep(j, 0, 2) {
				int pl = err[j + 1];
				if (i & (1 << j)) cri[pl] = g[1][pl];
				else cri[pl] = g[other][pl];
			}
			if (judge()) output();
		}
		
		rep(und, 1, 3) {
			int undpl = err[und]; 
			srep(i, 0, (1 << 2)) {
				int ptr = 0;
				rep(j, 0, 2) {
					if (j + 1 == und) continue;
					int pl = err[j + 1];
					if (i & (1 << ptr)) cri[pl] = g[1][pl];
					else cri[pl] = g[other][pl];
					ptr++;
				}
				//if (judge()) output(); 
				int candid = -1;
				rep(i, 1, n) {
					int res = 0;
					rep(j, 1, m) {
						if (j == undpl) continue;
						if (cri[j] != g[i][j]) res++;
					}
					if (res > 2) {
						goto fail;
					}
					else if (res == 2){	
						int _candid = g[i][undpl];
						if (candid == -1 || candid == _candid) candid = _candid;
						else {
							goto fail;
						}
					}
				}
				if (candid == -1) candid = 1;
				cri[undpl] = candid;
				output();
				fail:;
			}
		} 
	}
	puts("No");
	return 0;
}