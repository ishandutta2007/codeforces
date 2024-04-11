#include <bits/stdc++.h>

const int N = 1000;

int l[N + 5], p[N + 5], h, v;

std::bitset<N*N>f[N + 5];

std::vector<int>ah[2], av[2], bh, bv;

void solve() {
	int sl = 0, sp = 0;
	scanf("%d", &h); for(int i=1;i<=h;i++) scanf("%d", &l[i]), sl += l[i];
	scanf("%d", &v); for(int i=1;i<=v;i++) scanf("%d", &p[i]), sp += p[i];
	if( h != v || (sl & 1) || (sp & 1) ) {puts("No"); return ;}
	
	f[0] = 1; for(int i=1;i<=h;i++) f[i] = f[i - 1] | (f[i - 1] << l[i]);
	if( f[h][sl >> 1] ) {
		int t = (sl >> 1); ah[0].clear(), ah[1].clear(), bh.clear();
		for(int i=h;i>=1;i--) {
			if( f[i - 1][t] ) ah[0].push_back(i);
			else ah[1].push_back(i), t -= l[i];
		}
	} else {puts("No"); return ;}
	
	f[0] = 1; for(int i=1;i<=v;i++) f[i] = f[i - 1] | (f[i - 1] << p[i]);
	if( f[h][sp >> 1] ) {
		int t = (sp >> 1); av[0].clear(), av[1].clear(), bv.clear();
		for(int i=v;i>=1;i--) {
			if( f[i - 1][t] ) av[0].push_back(i);
			else av[1].push_back(i), t -= p[i];
		}
	} else {puts("No"); return ;}
	
	if( ah[0].size() < av[0].size() ) {
		std::sort(ah[0].begin(), ah[0].end(), [](int x, int y) {return l[x] > l[y];});
		std::sort(ah[1].begin(), ah[1].end(), [](int x, int y) {return l[x] > l[y];});
		for(auto x : ah[0]) bh.push_back(x);
		for(auto x : ah[1]) bh.push_back(-x);
		
		std::sort(av[0].begin(), av[0].end(), [](int x, int y) {return p[x] < p[y];});
		std::sort(av[1].begin(), av[1].end(), [](int x, int y) {return p[x] < p[y];});
		for(auto x : av[0]) bv.push_back(x);
		for(auto x : av[1]) bv.push_back(-x);
	} else {
		std::sort(ah[0].begin(), ah[0].end(), [](int x, int y) {return l[x] < l[y];});
		std::sort(ah[1].begin(), ah[1].end(), [](int x, int y) {return l[x] < l[y];});
		for(auto x : ah[0]) bh.push_back(x);
		for(auto x : ah[1]) bh.push_back(-x);
		
		std::sort(av[0].begin(), av[0].end(), [](int x, int y) {return p[x] > p[y];});
		std::sort(av[1].begin(), av[1].end(), [](int x, int y) {return p[x] > p[y];});
		for(auto x : av[0]) bv.push_back(x);
		for(auto x : av[1]) bv.push_back(-x);
	}
	
	puts("Yes"); int nx = 0, ny = 0;
	for(int i=0;i<h;i++) {
		printf("%d %d\n", nx, ny);
		if( ah[0].size() < av[0].size() ) {
			if( bh[i] > 0 ) nx += l[bh[i]];
			else nx -= l[-bh[i]];
		} else {
			if( bv[i] > 0 ) ny += p[bv[i]];
			else ny -= p[-bv[i]];
		}
		
		printf("%d %d\n", nx, ny);
		if( ah[0].size() < av[0].size() ) {
			if( bv[i] > 0 ) ny += p[bv[i]];
			else ny -= p[-bv[i]];
		} else {
			if( bh[i] > 0 ) nx += l[bh[i]];
			else nx -= l[-bh[i]];
		}
	}
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}