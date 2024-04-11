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
#define maxn 400020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define left LEFT
#define right RIGHT
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

int n, a[maxn], res = 0; 

struct ele{
	ll v, id, sum;
	ele(ll v, ll id, ll sum) : v(v), id(id), sum(sum){}
	ele(){}
	bool operator < (const ele b) const{
		return v == b.v ? id < b.id : v < b.v;
	}
}left[maxn], right[maxn];

void solve(int l, int r){
	if (r <= l) return;
	int mid = ((r - l) >> 1) + l;
	solve(l, mid), solve(mid + 1, r);
	
	ll sum = 0;
	per(i, mid, l) left[i] = ele(a[i] - sum, i, sum), sum += a[i];
	sort(left + l, left + mid + 1);
	
	sum = 0;
	rep(i, mid + 1, r) right[i] = ele(a[i] - sum, i, sum), sum += a[i];
	sort(right + mid + 1, right + r + 1);
	
	int ptr = l;
	per(i, r, mid + 1){
		while (ptr <= mid && right[i].v + left[ptr].v < 0) ptr++;
		rep(j, ptr, mid){
			if ((right[i].sum + left[j].sum) == (a[right[i].id] ^ a[left[j].id])) res++;
		}
	}
}
ll pre[maxn];
int main(){
	read(n); rep(i, 1, n) read(a[i]); //pre[i] = pre[i - 1] + a[i];
	rep(i, 1, n - 1) if (a[i] == a[i + 1]) res--; 
	/*
	rep(l, 1, n - 2) rep(r, l + 2, n){
		if ((a[l] ^ a[r]) == pre[r - 1] - pre[l]) cerr << l << ' ' << r << endl;
	}
	*/
	solve(1, n);
	write(res);
	return 0;
}