#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define ui unsigned int
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define pque priority_queue
const int mod = 1000000009;

ll binpow(ll a, ll n){
    ll tmp;
    if (n == 0){
        return 1;
	}
    tmp = binpow(a, n / 2);
    tmp = (tmp * tmp) % mod;
    if (n % 2 == 0){
        return tmp;
    }
    return (a * tmp) % mod;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, a, b, k, m, q, tmp = 0, ans, t = 1;
	char c;
	cin >> n >> a >> b >> k;
	for (int i = 0; i < k; i++){
		cin >> c;
		if (c == '+'){
			tmp += (binpow(a, n - i) * binpow(b, i));
		}
		else{
			tmp -= (binpow(a, n - i) * binpow(b, i));
		}
		tmp %= mod;
	}
	m = (n + 1) / k;
	q = (b * binpow(a, mod - 2)) % mod;
	q = binpow(q, k);
	if (q == 1){
		ans = (tmp * m) % mod;
		if (ans < 0){
			ans += mod;
		}
		cout << ans;
		return 0;
	}
	ans = (binpow(q, m) - 1) % mod;
	ans = (ans * binpow(q - 1, mod - 2)) % mod;
	ans = (ans * tmp) % mod;
	/*
	for (int i = 0; i <= m; i++){
		ans += (tmp * t) % mod;
		ans %= mod;
		t = (t * q) % mod;
	}
	*/
	if (ans < 0){
		ans += mod;
	}
	cout << ans;
}