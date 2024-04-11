#include <bits/stdc++.h>

const int N = 200000;

char s[N + 5]; int n;

void solve() {
	int ta = 0, tb = 0; scanf("%s", s), n = strlen(s);
	for(int i=0;i<n;i++) {
		if( s[i] == 'A' ) {
			ta++;
		} else {
			if( ta ) ta--;
			else if( tb ) tb--;
			else tb++;
		}
	}
	printf("%d\n", ta + tb);
}

int main() {
	int T; scanf("%d", &T);
	while( T-- ) solve();
}