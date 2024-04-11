#include <bits/stdc++.h>

typedef long long ll;

const ll INF = (ll)(1E14);

ll S, K; int cnt; char result[20];
bool query(ll x) {
	if( x < 0 || x > INF ) puts("WA 3"), exit(0);
	cnt++; if( cnt > 105 ) puts("WA 1"), exit(0);
	
	printf("? %lld\n", x), fflush(stdout);
	
	scanf("%s", result);
	if( result[0] == 'F' ) {
		if( result[1] == 'i' )
			puts("WA 2"), exit(0);
		else {
			assert( K >= x );
			K -= x;
			return false;
		}
	} else {
		S = x, K += x;
		return true;
	}
}
void answer(ll x) {
	printf("! %lld\n", x), fflush(stdout);
}

bool check(ll M) {
	while( K < M ) query(S);
	return query(M);
}
void solve() {
	cnt = 0;
	
	for(S = 0, K = 1; K <= INF && query(K); ) ;
	
	int t = 0; ll L = S, R = std::min((S << 1) - 1, INF);
	while( L < R ) {
		ll M; if( t ) {
			if( t == 1 ) M = L + (ll)ceil((R - L) / 2.25);
			else M = (L + R + 1) >> 1;
		} else {
			M = L + (ll)ceil((R - L) / 3.06);
		}
		
		if( check(M) ) {
			t++;
			L = M;
		} else {
			t = (t == 0) ? 0 : t - 1;
			R = M - 1;
		}
	}
	answer(L);
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}