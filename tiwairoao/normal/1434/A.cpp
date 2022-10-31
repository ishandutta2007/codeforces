#include <bits/stdc++.h>

const int N = 100000;

int a[6], b[N + 5];

int d[N + 5][6], p[N + 5];

int main() {
	for(int i=0;i<6;i++) scanf("%d", &a[i]);
	
	int n; scanf("%d", &n);
	std::set<std::pair<int, int> >st;
	for(int i=1;i<=n;i++) {
		scanf("%d", &b[i]);
		for(int j=0;j<6;j++) d[i][j] = b[i] - a[j];
		std::sort(d[i], d[i] + 6), p[i] = 0;
		st.insert(std::make_pair(d[i][0], i));
	}
	
	int ans = (st.rbegin()->first) - (st.begin()->first);
	while( true ) {
		int x = st.begin()->second; st.erase(st.begin()), p[x]++;
		if( p[x] == 6 ) break;
		else st.insert(std::make_pair(d[x][p[x]], x));
		ans = std::min(ans, (st.rbegin()->first) - (st.begin()->first));
	}
	printf("%d\n", ans);
}