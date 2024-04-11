#include <bits/stdc++.h>
using namespace std;

int m, n;

int ask(int x) {
	printf("%d\n", x);
	fflush(stdout);
	cin >> x;
	return x;
}

int A[66];

main(void) {
	cin >> m >> n;
	for(int i = 1; i <= n; ++ i) {
		A[i] = ask(m);
		if(!A[i]) break;
	}
	if(!A[1]) {
		return 0;
	}
	
	int now = 0;
	
	int it = 0;
	
	for(int i = 29; i >= 0; -- i) if((now + (1 << i)) < m) {
		int x = ask(now + (1 << i));
		it = it % n + 1;
		if(A[it] == 1) {
			x = -x;
		}
		if(!x) {
			return 0;
		}
		if(x == 1){
			now += (1 << i);
		}
	}
}