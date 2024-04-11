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
#define maxn 200020
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
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

int ct = 0; pii ans[maxn << 3]; int cs = 0;

set<int> s[4];
set<int> :: iterator it, it2;
void arr321(int j, int k) {
	++ct;
	ans[++cs] = pii(ct, j);
	ans[++cs] = pii(ct, k);
	int last = j;
	for (auto it = s[3].rbegin(); it != s[3].rend(); it++){
		++ct;
		ans[++cs] = pii(ct, last);
		ans[++cs] = pii(ct, *it);
		last = *it;
	}
}
void arr31(int j) {
	++ct;
	ans[++cs] = pii(ct, j);
	int last = j;
	for (auto it = s[3].rbegin(); it != s[3].rend(); it++){
		++ct;
		ans[++cs] = pii(ct, last);
		ans[++cs] = pii(ct, *it);
		last = *it;
	}
}
void arr21(int i, int j) {
	++ct;
	ans[++cs] = pii(ct, i);
	ans[++cs] = pii(ct, j);
}
void arr1(int i) {
	++ct;
	ans[++cs] = pii(ct, i);
}


int main(){
	int n, x;
	read(n); 
	rep(i, 1, n) read(x), s[x].insert(i); 
	while (!s[3].empty() && !s[2].empty() && !s[1].empty()) {
		int x = *(--s[3].end()); 
		it = s[2].lower_bound(x);
		if (it == s[2].end()) break;
		it2 = s[1].lower_bound(*it);
		if (it2 == s[1].end()) break;
		arr321(*it, *it2);
		s[3].clear(), s[2].erase(it), s[1].erase(it2);  
	}
	while (!s[3].empty() && !s[1].empty()) {
		int x = *(--s[3].end()); 
		it = s[1].lower_bound(x);
		if (it == s[1].end()) break;
		arr31(*it);
		s[3].clear(), s[1].erase(it);
	}
	while (!s[2].empty() && !s[1].empty()) {
		int x = *s[2].begin(); 
		it = s[1].lower_bound(x);
		if (it == s[1].end()) break;
		arr21(x, *it);
		s[2].erase(x), s[1].erase(it); 
	} 
	while (!s[1].empty()) {
		arr1(*s[1].begin());
		s[1].erase(s[1].begin());
	}
	if (!s[2].empty() || !s[3].empty() || ct > n) write(-1);
	else {
		write(cs);
		rep(i, 1, cs) write(n + 1 - ans[i].fi, ' '), write(ans[i].se);
	}
	
	/*
	while (!s[1].empty() && !s[2].empty() && !s[3].empty()) { 
		arr321(*s[3].begin(), *s[2].begin(), *s[1].begin());
		s[3].erase(s[3].begin()), s[2].erase(s[2].begin()), s[1].erase(s[1].begin());
	}
	while (!s[1].empty() && !s[3].empty()) { 
		arr31(*s[3].begin(), *s[1].begin());
		s[3].erase(s[3].begin()), s[1].erase(s[1].begin());
	}
	while (!s[1].empty() && !s[2].empty()) { 
		arr21(*s[2].begin(), *s[1].begin());
		s[2].erase(s[2].begin()), s[1].erase(s[1].begin());
	} 
	*/
	
	return 0;
}