#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i, x, n) for(int i=x;i<n;i++)

const int B = 100;
const int N = 200000;

int sa[N + 5], rnk[N + 5], h[N + 5], st[20][N + 5], lg[N + 5];
int nsa[N + 5], nrnk[N + 5], b[N + 5];
void get_sa(char *S, int n) {
	rep(i, 0, 128) b[i] = 0;
	rep(i, 0, n) b[S[i]]++;
	rep(i, 1, 128) b[i] += b[i-1];
	rep(i, 0, n) sa[--b[S[i]]] = i;
	rnk[sa[0]] = 0; rep(i, 1, n) rnk[sa[i]] = rnk[sa[i-1]] + (S[sa[i]] != S[sa[i-1]]);
	for(int k=1;rnk[sa[n-1]]!=n-1;k<<=1) {
		int l = rnk[sa[n-1]];
		rep(i, 0, l + 1) b[i] = 0;
		rep(i, 0, n) b[rnk[i]]++;
		rep(i, 1, l + 1) b[i] += b[i-1];
		for(int i=n-1;i>=0;i--)
			if( sa[i] >= k ) nsa[--b[rnk[sa[i]-k]]] = sa[i] - k;
		rep(i, n-k, n) nsa[--b[rnk[i]]] = i;
		rep(i, 0, n) sa[i] = nsa[i], nrnk[i] = rnk[i];
		rnk[sa[0]] = 0; rep(i, 1, n) rnk[sa[i]] = rnk[sa[i-1]] + (nrnk[sa[i]] != nrnk[sa[i-1]] || nrnk[sa[i]+k] != nrnk[sa[i-1]+k]);
	}
	
	for(int i=0,k=0;i<n;i++) {
		if( rnk[i] == 0 ) h[rnk[i]] = 0;
		else {
			int j = sa[rnk[i] - 1];
			if( k ) k--;
			while( S[i + k] == S[j + k] ) k++;
			h[rnk[i]] = k;
		}
	}
/*
	for(int i=0;i<n;i++) {
		printf("%d : ", h[i]);
		int x = sa[i];
		for(int j=x;j<n;j++)
			putchar(S[j]);
		puts("");
	}
*/
	rep(i, 2, n + 1) lg[i] = lg[i >> 1] + 1;
	rep(i, 0, n) st[0][i] = h[i];
	for(int j=1,t=1;j<20;j++,t<<=1)
		for(int i=0;i+t<n;i++)
			st[j][i] = min(st[j - 1][i], st[j - 1][i + t]);
}

char str[2*N + 5]; int lenS, lenT;
int lcp(int l, int r) {
	if( l == r ) return lenS + lenT;
	l = rnk[l], r = rnk[r];
	if( l > r ) swap(l, r); l++;
	int k = lg[r - l + 1], p = (1 << k);
	return min(st[k][l], st[k][r-p+1]);
}
int get(int l1, int l2, int k) {
	int p = lcp(l1, l2);
	if( p >= k ) return 0;
	else return (str[l1 + p] < str[l2 + p] ? -1 : 1);
}
bool cmp(int x, int y) {
	int ret; bool tag = false;
	if( x > y ) swap(x, y), tag = true;
	if( x + lenT <= y ) {
		int p = get(lenS, x, lenT);
		if( p ) ret = p;
		else {
			p = get(x, x + lenT, y - (x + lenT));
			ret = (p ? p : get(y - lenT, lenS, lenT));
		}
	} else {
		int p = get(lenS, x, y - x);
		if( p ) ret = p;
		else {
			p = get(lenS + (y - x), lenS, lenT - (y - x));
			ret = (p ? p : get(x, lenS + (lenT - (y - x)), y - x));
		}
	}
	if( ret == 0 ) ret = -1;
	return (tag ? -ret : ret) == -1 ? true : false;
}

int a[N + 5], rk[N + 5];

struct query{int l, r, x;};
vector<query>qry[B + 5][B + 5];

int st2[20][N + 5], ans[N + 5];
int rmq(int l, int r) {
	int k = lg[r - l + 1], p = (1 << k);
	return rk[st2[k][l]] < rk[st2[k][r-p+1]] ? st2[k][l] : st2[k][r-p+1];
}
void update(int x, int k) {
	if( ans[x] == -1 || rk[k] < rk[ans[x]] )
		ans[x] = k;
}
void solve(int k, int r) {
	int cnt = 0;
	for(int i=r;i<=lenS;i+=k) st2[0][cnt++] = i;
	for(int j=1,t=1;j<=20;j++,t<<=1) {
		for(int i=0;i+t<cnt;i++)
			st2[j][i] = (rk[st2[j-1][i]] < rk[st2[j-1][i+t]] ? st2[j-1][i] : st2[j-1][i+t]);
	}
	for(auto x : qry[k][r]) update(x.x, rmq(x.l, x.r));
}

int main() {
	scanf("%s", str), lenS = strlen(str);
	scanf("%s", str + lenS), lenT = strlen(str + lenS);
	get_sa(str, lenS + lenT + 1);
	
	for(int i=0;i<=lenS;i++) a[i] = i;
	sort(a, a + lenS + 1, cmp);
	for(int i=0;i<=lenS;i++) rk[a[i]] = i;
	
	for(int i=0;i<=lenS;i++) st2[0][i] = i;
	for(int j=1,t=1;j<=20;j++,t<<=1) {
		for(int i=0;i+t<=lenS;i++)
			st2[j][i] = (rk[st2[j-1][i]] < rk[st2[j-1][i+t]] ? st2[j-1][i] : st2[j-1][i+t]);
	}
	
	int q; scanf("%d", &q);
	for(int i=1,l,r,k,x,y;i<=q;i++) {
		scanf("%d%d%d%d%d", &l, &r, &k, &x, &y), ans[i] = -1;
		if( k < B ) {
			for(int j=x;j<=y;j++) {
				int l0 = ceil(1.0 * (l - j) / k), r0 = floor(1.0 * (r - j) / k);
				if( l0 <= r0 ) qry[k][j].push_back((query){l0, r0, i});
			}
		} else {
			for(int l0=x,r0=y;l0<=lenS;l0+=k,r0=min(r0+k,lenS)) {
				int l1 = max(l, l0), r1 = min(r, r0);
				if( l1 <= r1 ) update(i, rmq(l1, r1));
			}
		}
	}
	rep(i, 1, B) rep(j, 0, i) if( !qry[i][j].empty() ) solve(i, j);
	for(int i=1;i<=q;i++) printf("%d%c", ans[i], (i == q ? '\n' : ' '));
}