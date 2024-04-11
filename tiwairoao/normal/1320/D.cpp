#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 200000;

int sa[MAXN + 5], rnk[MAXN + 5], c[MAXN + 5];
int nsa[MAXN + 5], nrnk[MAXN + 5];
void get_sa(int *S, int n, int m) {
    for(int i=0;i<m;i++) c[i] = 0;
    for(int i=0;i<n;i++) c[S[i]]++;
    for(int i=1;i<m;i++) c[i] += c[i-1];
    for(int i=n-1;i>=0;i--) sa[--c[S[i]]] = i;
    rnk[sa[0]] = 0;
    for(int i=1;i<n;i++) rnk[sa[i]] = rnk[sa[i-1]] + (S[sa[i]] != S[sa[i-1]]);
    for(int k=1;rnk[sa[n-1]]!=n-1;k<<=1) {
        int cnt = 0;
        for(int i=n-k;i<n;i++) nsa[cnt++] = i;
        for(int i=0;i<n;i++)
            if( sa[i] >= k ) nsa[cnt++] = sa[i] - k;
        for(int i=0;i<n;i++) nrnk[i] = rnk[i];
        for(int i=0;i<n;i++) c[i] = 0;
        for(int i=0;i<n;i++) c[nrnk[i]]++;
        for(int i=1;i<n;i++) c[i] += c[i-1];
        for(int i=n-1;i>=0;i--) sa[--c[nrnk[nsa[i]]]] = nsa[i];
        rnk[sa[0]] = 0;
        for(int i=1;i<n;i++) rnk[sa[i]] = rnk[sa[i-1]] + (nrnk[sa[i]] != nrnk[sa[i-1]] || nrnk[sa[i]+k] != nrnk[sa[i-1]+k]);
    }
}
int ht[MAXN + 5];
void get_height(int *S, int n) {
    int k = 0;
    for(int i=0;i<n;i++) {
        if( rnk[i] == 0 ) ht[rnk[i]] = 0;
        else {
            if( k ) k--;
            while( S[i+k] == S[sa[rnk[i]-1]+k] )
                k++;
            ht[rnk[i]] = k;
        }
    }
}
int lg[MAXN + 5], st[20][MAXN + 5];
void get_st(int n) {
	for(int i=2;i<=n;i++) lg[i] = lg[i>>1] + 1;
	for(int i=0;i<n;i++) st[0][i] = ht[i];
	for(int j=1;j<20;j++) {
		int t = (1 << (j - 1));
		for(int i=0;i+t<n;i++)
			st[j][i] = min(st[j-1][i], st[j-1][i+t]);
	}
}
int rmq(int x, int y) {
	if( x > y ) swap(x, y); x++;
	int k = lg[y - x + 1], l = (1 << k);
	return min(st[k][x], st[k][y-l+1]);
}

bool check(int l1, int r1, int l2, int r2) {
	l1--, r1--, l2--, r2--;
	if( r1 - l1 != r2 - l2 ) return false;
	if( l1 == l2 || r1 - l1 <= 0 ) return true;
	return rmq(rnk[l1], rnk[l2]) >= r1 - l1;
}

int a[MAXN + 5], n, q;

int s[MAXN + 5], l[MAXN + 5], r[MAXN + 5];
int sum(int le, int ri) {
	return s[ri] - s[le - 1];
}
int query(int le, int ri) {
	return (ri - le + 1) - sum(le, ri);
}
struct node{
	int l, r; node() {}
	node(int _l, int _r) : l(_l), r(_r) {}
}o[MAXN + 5]; int cnt;
bool cmpl(node x, node y) {return x.l < y.l;}
bool cmpr(node x, node y) {return x.r < y.r;}
int b[MAXN + 5];
void get() {
	l[1] = 1; for(int i=1+1;i<=n;i++) l[i] = (a[i] == a[i-1] ? l[i-1] : i);
	r[n] = n; for(int i=n-1;i>=1;i--) r[i] = (a[i] == a[i+1] ? r[i+1] : i);
	for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
	
	for(int i=1;i<=n;i++)
		if( a[i] == 1 && l[i] == i && ((r[i] - l[i] + 1) & 1) )
			o[++cnt] = node(l[i], r[i]);
	
	for(int i=1;i<cnt;i++)
		b[i] = (o[i + 1].l - o[i].r - 1) - sum(o[i].r + 1, o[i + 1].l - 1);
	
	if( cnt >= 2 ) get_sa(b + 1, cnt, n), get_height(b + 1, cnt), get_st(cnt);
}

char t[MAXN + 5];
int main() {
	scanf("%d%s%d", &n, t + 1, &q);
	for(int i=1;i<=n;i++)
		a[i] = t[i] - '0';
	get();
	for(int i=1;i<=q;i++) {
		int l1, l2, len; scanf("%d%d%d", &l1, &l2, &len);
		int r1 = l1 + len - 1, r2 = l2 + len - 1;
		
		if( r[l1] >= r1 && r[l2] >= r2 && a[l1] == a[l2] ) puts("Yes");
		else {
			bool fl1 = (a[l1] == 1) && ((r[l1] - l1 + 1) & 1);
			bool fl2 = (a[l2] == 1) && ((r[l2] - l2 + 1) & 1);
			bool fr1 = (a[r1] == 1) && ((r1 - l[r1] + 1) & 1);
			bool fr2 = (a[r2] == 1) && ((r2 - l[r2] + 1) & 1);
			if( fl1 != fl2 || fr1 != fr2 )
				puts("No");
			else {
				if( cnt >= 1 ) {
					int p1 = upper_bound(o + 1, o + cnt + 1, node(l1, l1), cmpl) - o;
					int q1 = lower_bound(o + 1, o + cnt + 1, node(r1, r1), cmpr) - o - 1;
					int p2 = upper_bound(o + 1, o + cnt + 1, node(l2, l2), cmpl) - o;
					int q2 = lower_bound(o + 1, o + cnt + 1, node(r2, r2), cmpr) - o - 1;
					
					bool f = check(p1, q1, p2, q2), g = true;
					
					if( p1 <= q1 && p2 <= q2 ) {
						if( query(l1, o[p1].l - 1) != query(l2, o[p2].l - 1) ) g = false;
						if( query(o[q1].r + 1, r1) != query(o[q2].r + 1, r2) ) g = false;
					}
					else g = (sum(l1, r1) == sum(l2, r2));
					
					puts(f && g ? "Yes" : "No");
				}
				else puts("Yes");
			}
		}
	}
}