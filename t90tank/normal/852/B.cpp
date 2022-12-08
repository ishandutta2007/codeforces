#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const ll mod = 1e9L + 7;

const int N = 100, M = 1e6L + 11;
ll cnt[N];

ll pre[M];
ll mid[M];
ll suf[M];

ll num[M], nc[M];

int m;

using vl = vector <ll>;

vl mul(vl a, vl b) {
	vl r(m);
	for(int i = 0; i < m; i ++)
		for(int j = 0; j < m; j ++) {
			r[(i + j) % m] += a[i] * b[j];
			r[(i + j) % m] %= mod;
		}
	return r;
}

vl qpow(vl a, ll b) {
	if(b == 0) {
		vl r(m); r[0] = 1;
		return r;
	}
	vl r = a; b --;
	for(; b; b /= 2) {
		if(b & 1)
			r = mul(r, a);
		a = mul(a, a);
	}
	return r;
}

int main() {
	int n, l, m; scanf("%d%d%d", &n, &l, &m);
	
	for(int i = 0; i < n; i ++) {
		int x; scanf("%d", &x); x %= m;
		cnt[x] ++;
		pre[i] = x;
		num[i] = x;
		nc[i] = 1;
	}
	
	ll ans = 0;
	
	{
		vl v(cnt, cnt + m);
		
		fill(cnt, cnt + m, 0);
		for(int i = 0; i < n; i ++) {
			scanf("%lld", mid + i); mid[i] %= m;
			cnt[mid[i]] ++;
		}
		for(int i = 0; i < n; i ++)
			scanf("%lld", suf + i);
		
		vl u(cnt, cnt + m);
		::m = m;
		
		v = mul(v, qpow(u, l - 2));
		/*
		for(int i = 0; i < m; i ++)
			cout << v[i] << '\n';
		*/
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
				if((j + mid[i] + suf[i]) % m == 0) {
					ans += v[j];
					ans %= mod;
				}
					
	}
	cout << ans << '\n';
	
	return 0;
}