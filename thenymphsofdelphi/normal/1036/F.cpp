#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

const int inf = 4e18;

int mul(int x, int y){
	if (x > inf / y){
	    return inf;
	}
	return x * y;
}

int binpow(int x, int y){
	long long ans = 1;
	while (y){
		if (y & 1){
		    ans = mul(ans, x);
		}
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}

long long f[61];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int q, n;
	cin >> q;
	while (q--){
		cin >> n;
		for (int i = 60; i >= 1; --i){
			f[i] = (int)((double)pow((double)n, (double)(1.0 / i)) + (double)1.0);
			while (binpow(f[i], i) > n){
			    f[i]--;
			}
			f[i]--;
			for (int j = i + i; j <= 60; j += i){
			    f[i] -= f[j];
			}
		}
		cout << f[1] << '\n';
	}
}