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
#define maxn
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

set<int> s;
set<int> :: iterator it;
multiset<int> q;
ll sum = 0;

void add(int x) {
	s.insert(x);
	it = s.lower_bound(x);
	int pre = -1, suf = -1;
	if (it != s.begin()) {	
		it--;
		pre = *it;
		it++;
	}
	it++;
	if (it != s.end()) {
		suf = *it; 
	}
	if (pre == -1 && suf != -1) {
		q.insert(suf - x);
		sum += suf - x;
	}
	if (pre != -1 && suf == -1) {
		q.insert(x - pre);
		sum += x - pre;
	}
	if (pre != -1 && suf != -1) {
		q.erase(q.lower_bound(suf - pre));
		q.insert(x - pre), q.insert(suf - x);
	} 
}
void del(int x) {
	it = s.lower_bound(x);
	int pre = -1, suf = -1;
	if (it != s.begin()) {
		it--;
		pre = *it;
		it++;
	}
	it++;
	if (it != s.end()) {
		suf = *it; 
	}
	s.erase(x);
	if (pre == -1 && suf != -1) {
		q.erase(q.lower_bound(suf - x));
		sum -= suf - x;
	}
	if (pre != -1 && suf == -1) {	
		q.erase(q.lower_bound(x - pre)); 
		sum -= x - pre;
	}
	if (pre != -1 && suf != -1) {
		q.erase(q.lower_bound(x - pre));
		q.erase(q.lower_bound(suf - x)); 
		q.insert(suf - pre); 
	} 
}
int main(){
	int n, m, x, op;
	read(n); read(m);
	rep(i, 1, n) read(x), add(x);
	if (!q.empty()) printf("%lld\n", sum - *q.rbegin());
	else printf("0\n");
	rep(i, 1, m) {
		read(op), read(x);
		if (op) add(x);
		else del(x);
		if (!q.empty()) printf("%lld\n", sum - *q.rbegin());
		else printf("0\n");
	}
	return 0;
}