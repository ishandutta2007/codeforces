#include <bits/stdc++.h>

const int N = 200000;
const int B = 450;

int a[N + 5], n;

int b[N + 5], tot, cnt[N + 5], tmp[2*N + 5];
int solve1() {
	for(int i=1;i<=n;i++) cnt[a[i]]++;
	
	int pos = n + 1, mx = 0;
	for(int i=1;i<=n;i++) if( cnt[i] > cnt[mx] ) mx = i;
	for(int i=1;i<=n;i++) if( cnt[i] /*>= B*/ ) b[++tot] = i;
	if( !tot ) return 0;
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=tot;j++) if( mx != b[j] && cnt[b[j]] == cnt[mx] ) {
			pos = i; break;
		}
		if( pos != n + 1 ) break; else cnt[a[i]]--;
//		if( cnt[mx] < B ) break;
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

int solve2() {
	return 0;
}

int main() {
	scanf("%d", &n); for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	printf("%d\n", std::max(solve1(), solve2()));
}