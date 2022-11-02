#include <bits/stdc++.h>

const int N = 200000;
const int B = 450;

int a[N + 5], n;

int b[N + 5], tot, cnt[N + 5], tmp[2*N + 5];
int solve1() {
	for(int i=1;i<=n;i++) cnt[a[i]]++;
	
	int pos = n + 1, mx = 0;
	for(int i=1;i<=n;i++) if( cnt[i] > cnt[mx] ) mx = i;
	for(int i=1;i<=n;i++) if( cnt[i] >= B ) b[++tot] = i;
	if( !tot ) return 0;
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=tot;j++) if( mx != b[j] && cnt[b[j]] == cnt[mx] ) {
			pos = i; break;
		}
		if( pos != n + 1 ) break; else cnt[a[i]]--;
		if( cnt[mx] < B ) break;
	}
	
	int ret = n - pos + 1;
	for(int j=1;j<=tot;j++) if( mx != b[j] ) {
		int p = 0; tmp[p] = n + 1;
		for(int i=n;i>=pos;i--) {
			if( a[i] == mx ) p++;
			else if( a[i] == b[j] ) p--;
			if( !tmp[p + N] ) tmp[p + N] = i;
		}
		for(int i=pos-1;i>=1;i--) {
			if( a[i] == mx ) p++;
			else if( a[i] == b[j] ) p--;
			
			if( tmp[p + N] ) ret = std::max(ret, tmp[p + N] - i);
			else tmp[p + N] = i;
		}
		
		p = 0; tmp[p] = 0;
		for(int i=n;i>=1;i--) {
			if( a[i] == mx ) p++;
			else if( a[i] == b[j] ) p--;
			tmp[p + N] = 0;
		}
	}
	return ret;
}

int nw[N + 5], nxt[N + 5], t1[N + 5], t2[N + 5];
int solve2() {
	for(int i=1;i<=n;i++) nw[i] = n + 1; nxt[n + 1] = n + 1;
	for(int i=n;i>=1;i--) nxt[i] = nw[a[i]], nw[a[i]] = i;
	for(int i=1;i<=n;i++) t1[i] = i, t2[i] = nxt[i];
	
	int ret = 0;
	for(int i=1;i<=B;i++) {
		int mn1 = n + 1, smn1 = n + 1, mn2 = n + 1;
		for(int j=n;j>=1;j--) {
			if( t1[j] < mn1 ) smn1 = mn1, mn1 = t1[j];
			else if( t1[j] < smn1 ) smn1 = t1[j];
			
			if( t2[j] < mn2 ) mn2 = t2[j];
			
			if( smn1 < mn2 ) ret = std::max(ret, mn2 - j);
			
			t1[j] = nxt[t1[j]], t2[j] = nxt[t2[j]];
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n); for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	printf("%d\n", std::max(solve1(), solve2()));
}