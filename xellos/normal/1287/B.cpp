#include <cstdio>
#include <algorithm>

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	long long mask = 0;
	for(int i = 0; i < K; i++) mask |= 1LL<<(2*i);
	long long val[1600];
	for(int i = 0; i < N; i++) {
		static char buf[40];
		scanf("%s", buf);
		val[i] = 0;
		for(int j = 0; j < K; j++) {
			long long v = (buf[j] == 'S') ? 1 : ((buf[j] == 'E') ? 2 : 3);
			val[i] |= v<<(2*j);
		}
	}
	std::sort(val, val+N);
	int ans = 0;
	for(int i = 0; i < N; i++) for(int j = i+1; j < N; j++) {
		long long w = val[i] ^ val[j];
		long long m = mask ^ ((w & mask) | ((w>>1) & mask));
		w |= (val[i] & m) | (val[i] & (m<<1));
		if(w >= val[i]) continue;
		int l = -1, r = i;
		while(r-l > 1) {
			int c = (l+r)/2;
			if(val[c] >= w) r = c;
			else l = c;
		}
		if(r < i && val[r] == w) ans++;
	}
	printf("%d\n", ans);
}