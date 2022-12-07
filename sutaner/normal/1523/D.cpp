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
    #define isletter(ch) ('0' <= ch && ch <= '1')
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

#define maxn 300020
#define maxm
#define maxs 
#define maxb 16
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m, p;
ll v[maxn];
int S[1 << maxb];
int lis[maxb], cs = 0;
char tmp[105];
int main(){
	
	srand(19260817);
	//rep(i, 1, 100) cout << rand() << endl; return 0;
	read(n, m, p);
	rep(i, 1, n) {
		reads(tmp);
		ll& x = v[i]; x = 0;
		srep(i, 0, m) x = (x << 1) + tmp[i] - '0'; 
	}
	
	int T = 15;
	
	int mx = -1; ll mx2 = -1;
	while (T--){	
		int id = 1ll * rand() * rand() % n + 1; //XXX
		
		//int bc = 0;
		//srep(i, 0, m) if ((v[id] >> i) & 1) bc++; 
		cs = 0;
		srep(i, 0, m) if ((v[id] >> i) & 1) lis[cs++] = i; 
		
		int SS = (1 << cs) - 1;
		rep(i, 1, n) {
			int nowS = 0;
			srep(j, 0, cs) {
				if ((v[i] >> lis[j]) & 1) {
					nowS ^= (1 << j);
				}
			}
			S[nowS]++;
		}
		
		//int mx = -1; ll mx2 = -1;
		for (int i = SS; i; i = (i - 1) & SS){
			int _SS = SS ^ i;
			int num = S[i]; for (int j = _SS; j; j = (j - 1) & _SS) num += S[i ^ j];
			
			if (num >= ((n + 1) >> 1)) {
				ll realS = 0;
				int bc = 0; srep(j, 0, cs) {
					if ((i >> j) & 1) {
						bc++;
						realS ^= (1ll << lis[j]);
					}
				}
				if (bc > mx) mx = bc, mx2 = realS;
			}
		}
		rep(i, 0, SS) S[i] = 0;
	}
	if (mx2 == -1) mx2 = 0;
	per(i, m - 1, 0){
		printf("%lld", (mx2 >> i) & 1);
	}
	return 0;
}