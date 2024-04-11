#include <bits/stdc++.h>
using namespace std;

#define int long long 

int n , m , x , y , k , d , p , mod;

int ans[1111111];

void godance(int now , int mod , int ddd , bool fan) {
	if(!now) {
		d = ddd - 1; return;
	}
	if(!fan) {
		int T = now / mod;
		if(now % mod) ++ T;
		ans[ddd] = (mod - now % mod) % mod;
		godance(T , mod , ddd + 1 , fan ^ 1);	
	}
	else {
		int T = now / mod;
		ans[ddd] = now % mod;
		godance(T , mod , ddd + 1 , fan ^ 1);
	}
}

bool solve(int p , int mod) {
	ans[0] = p % mod;
	int T = p / mod;
	d = 1;
	godance(T , mod , 1 , 0);
	return 1;
}

main(void) {
	cin >> p >> mod;
	if(!p) {
		puts("1");
		cout << 0 << endl;
		return 0;
	}
	if(solve(p , mod)) {
		cout << d + 1 << endl;
		for(int i = 0;i <= d;++ i) cout << ans[i] <<" ";
		puts("");
	}
	else {
		puts("-1");
	}
}