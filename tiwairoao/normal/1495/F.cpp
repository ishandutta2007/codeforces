#include <bits/stdc++.h>

typedef long long ll;

const int N = 200000;
const int S = 80*N;

int ch[2][S + 5], ncnt; ll tg[S + 5];

ll query(int x, int l, int r, int p) {
	if( !x ) return 0;
	
	int m = (l + r) >> 1;
	if( p <= m ) return query(ch[0][x], l, m, p) + tg[x];
	else return query(ch[1][x], m + 1, r, p) + tg[x];
}
int add(int pre, int l, int r, int p, ll k) {
	if( p < l ) return pre;
	
	int x = (++ncnt);
	ch[0][x] = ch[0][pre], ch[1][x] = ch[1][pre], tg[x] = tg[pre];
	if( r <= p ) {tg[x] += k; return x;}
	else {
		int m = (l + r) >> 1;
		ch[0][x] = add(ch[0][x], l, m, p, k);
		ch[1][x] = add(ch[1][x], m + 1, r, p, k);
		return x;
	}
}

int a[N + 5], b[N + 5], p[N + 5], rt[N + 5], n, q;

int stk[N + 5], tp;
int main() {
	scanf("%d%d", &n, &q);
	for(int i=1;i<=n;i++) scanf("%d", &p[i]); p[n + 1] = n + 1;
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	for(int i=1;i<=n;i++) scanf("%d", &b[i]);
	
	stk[++tp] = 1;
	for(int i=2;i<=n+1;i++) {
		rt[i] = add(rt[i - 1], 1, n, i - 1, a[i - 1]);
		
		while( tp && p[i] > p[stk[tp]] ) {
			int j = stk[tp--]; ll k = query(rt[i], 1, n, j);
			if( k > b[j] ) rt[i] = add(rt[i], 1, n, j, b[j] - k);
		}
		stk[++tp] = i;
	}
	
	ll ans = query(rt[n + 1], 1, n, 1);
	std::set<int>st; st.insert(1), st.insert(n + 1);
	for(int i=1,x;i<=q;i++) {
		scanf("%d", &x);
		if( x != 1 ) {
			if( st.count(x) ) {
				auto it = st.find(x);
				
				int l = -1, r = -1;
				it++; if( it != st.end() ) r = *it; it--;
				if( it != st.begin() ) it--, l = *it, it++;
				assert( l != -1 && r != -1 );
				
				ans -= query(rt[x], 1, n, l) + query(rt[r], 1, n, x) - query(rt[r], 1, n, l);
				
				st.erase(x);
			} else {
				auto it = st.insert(x).first;
				
				int l = -1, r = -1;
				it++; if( it != st.end() ) r = *it; it--;
				if( it != st.begin() ) it--, l = *it, it++;
				assert( l != -1 && r != -1 );
				
				ans += query(rt[x], 1, n, l) + query(rt[r], 1, n, x) - query(rt[r], 1, n, l);
			}
		}
		printf("%lld\n", ans);
	}
}