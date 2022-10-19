#include <bits/stdc++.h>
using namespace std;

#define int long long

main(void) {
	int q , n;
	cin >> n >> q;
	int y;
	while(q --) {
		scanf("%lld" , &y);
		for(int t = 0;t < 64;++ t) {
			int now = (1ll << t) - 1;
			int it = y - 2 * n;
			it = it % (now + 1);
			it = (it + now + 1) % (now + 1);
//			cerr << y <<" " << t <<" "<< it << endl;
			if(it) continue;
			int P = 2 * n + 1 + (y - 2 * n) / (now + 1);
			if(P & 1) continue;
			int x = P / 2;
//			cerr << x << endl;
			int nx = 2 * n - 2 * x + 1;
			int C = (2 * x - 1 - y) / nx;
//			cerr << C << " "<< endl;
//			system("pause");
			if(C >= (1ll << (t + 1)) - 1) continue;
			printf("%lld\n" , x);
			break;
		}
	}
}