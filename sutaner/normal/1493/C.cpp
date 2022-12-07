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

#define maxn 200020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, k;
char s[maxn];
int num[30];
int main(){
	int T; read(T);
	while (T--){
		srep(i, 0, 30) num[i] = 0;
		read(n, k);
		reads(s);
		srep(i, 0, n) num[s[i] - 'a']++;
		int rest = 0;
		srep(i, 0, 26) {
			num[i] %= k;
			rest += (num[i] == 0) ? 0 : (k - num[i]);
		} 
		if (!rest) {
			printf("%s\n", s);
			goto done;
		}
		per(i, n - 1, 0) {
			int x = s[i] - 'a';
			rest -= (num[x] == 0) ? 0 : (k - num[x]);
			num[x]--;
			if (num[x] == -1) num[x] = k - 1;
			rest += (num[x] == 0) ? 0 : (k - num[x]);
			
			srep(y, x + 1, 26) {
			
			
				rest -= (num[y] == 0) ? 0 : (k - num[y]);
				num[y]++;
				if (num[y] == k) num[y] = 0;
				rest += (num[y] == 0) ? 0 : (k - num[y]);
				
				
				if ((n - i - 1) >= rest && (n - i - 1) % k == rest % k) {
					srep(t, 0, i) printf("%c", s[t]);
					printf("%c", 'a' + y);
					int hhh = n - i - 1 - rest;
					srep(t, i + 1, n) {
						if (!hhh){
							srep(xx, 0, 26) {
								int _rest = (num[xx] == 0) ? 0 : (k - num[xx]);
								if (_rest) {
									printf("%c", 'a' + xx), num[xx]++;
									if (num[xx] == k) num[xx] = 0; 
									break;
								}
							}
						}
						else printf("%c", 'a'), hhh--;
					}
					printf("\n");
					goto done;
				} 
				
				
				rest -= (num[y] == 0) ? 0 : (k - num[y]);
				num[y]--;
				if (num[y] == -1) num[y] = k - 1;
				rest += (num[y] == 0) ? 0 : (k - num[y]);
				
				
			} 
		}
		printf("-1\n");
		done:;
	}
	return 0;
}