#include <stdio.h>

#define N	105

int main() {
	int t;
	
	scanf("%d", &t);
	while (t--) {
		static int a[N], cnt[N];
		int n, i, mx;
		
		scanf("%d", &n);
		for (i = 0; i < N; i++)
			cnt[i] = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]), cnt[a[i]]++;
		mx = 0;
		for (i = 0; i < N; i++)
			if (cnt[i] > mx)
				mx = cnt[i];
		if (cnt[0] > 0)
			printf("%d\n", n - cnt[0]);
		else
			printf("%d\n", n + (mx == 1));
	}	
	return 0;
}