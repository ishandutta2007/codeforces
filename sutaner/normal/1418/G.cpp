#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>

#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int  
#define ull unsigned long long int  
#define pll pair<ull, ull>
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 600020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}
int n, a[maxn]; ull v[maxn][4], v2[maxn][4];
ll ans = 0;
map<pll, int> s;
int num1[maxn], num2[maxn]; ull has1[maxn], has2[maxn];
void solve(int l, int r) {
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	solve(l, mid), solve(mid + 1, r);
	s.clear(); ull nowhash = 0, nowhash2 = 0; 
	int ptr = -1;
	per(i, mid, l) {
		nowhash ^= v[a[i]][num1[a[i]]];
		nowhash2 ^= v2[a[i]][num1[a[i]]];
		num1[a[i]]++;
		if (num1[a[i]] == 4) {
			ptr = i + 1;
			num1[a[i]]--;
			break;
		}
		nowhash ^= v[a[i]][num1[a[i]]];
		nowhash2 ^= v2[a[i]][num1[a[i]]];
		has1[i] = nowhash;
		has2[i] = nowhash2;
		s[pll(nowhash, nowhash2)]++;
	} 
	if (ptr == -1) ptr = l;
	rep(i, mid + 1, r) num2[a[i]] = 3;
	nowhash = nowhash2 = 0;
	rep(i, mid + 1, r) {
		nowhash ^= v[a[i]][num2[a[i]]];
		nowhash2 ^= v2[a[i]][num2[a[i]]];
		num2[a[i]]--;
		while (ptr <= mid && num1[a[i]] > num2[a[i]]) {
			s[pll(has1[ptr], has2[ptr])]--;
			num1[a[ptr]]--;
			ptr++;
		}
		if (num1[a[i]] > num2[a[i]]) break; 
		nowhash ^= v[a[i]][num2[a[i]]]; 
		nowhash2 ^= v2[a[i]][num2[a[i]]]; 
		ans += s[pll(nowhash, nowhash2)];
	}
	rep(i, l, mid) num1[a[i]] = 0;
	rep(i, mid + 1, r) num2[a[i]] = 0;
}
int main(){
	srand(time(NULL));
	read(n);
	rep(i, 1, n) read(a[i]), v[i][0] = v[i][3] = 0, v[i][1] = 1ull * rand() * rand() * rand(), v[i][2] = 1ull * rand() * rand() * rand(), v2[i][0] = v2[i][3] = 0, v2[i][1] = 1ull * rand() * rand() * rand(), v2[i][2] = 1ull * rand() * rand() * rand();
	solve(1, n);
	printf("%lld\n", ans); 
	return 0;
}