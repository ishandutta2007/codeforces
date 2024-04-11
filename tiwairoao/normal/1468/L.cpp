#include <bits/stdc++.h>

const int N = 2000;

typedef long long ll;

const int prm[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

ll mmul(ll a, ll b, ll m) {
	return (a * b - (ll)((long double)a / m * b) * m + m) % m;
}
ll mpow(ll b, ll p, ll m) {
	ll r; for(r = 1; p; p >>= 1, b = mmul(b, b, m))
		if( p & 1 ) r = mmul(r, b, m);
	return r;
}
bool check(ll x, ll p, ll k) {
	ll s = mpow(p, k, x);
	if( s == 1 || s == x - 1 ) return true;
	for(; k != x - 1; k <<= 1) {
		s = mmul(s, s, x);
		if( s == x - 1 ) return true;
		else if( s == 1 ) return false;
	}
	return false;
}
bool is_prime(ll x) {
	if( x == 1 ) return false;
	for(int i=0;i<9;i++) {
		if( x == prm[i] ) return true;
		else if( x % prm[i] == 0 ) return false;
	}
	
	ll k = x - 1; while( k % 2 == 0 ) k >>= 1;
	for(int i=0;i<9;i++) if( !check(x, prm[i], k) )
		return false;
	return true;
}

std::vector<int>v[N + 5];
std::map<ll, int>mp; ll pr[N + 5]; int cnt;
int id(ll x) {
	if( !mp.count(x) ) mp[x] = (++cnt), pr[cnt] = x;
	return mp[x];
}

ll calc(ll x, int p) {
	if( p >= 10 ) {
		for(int i=2;i<=100;i++) {
			int c = 0; ll t = x;
			while( t % i == 0 ) t /= i, c++;
			if( c == p && t == 1 ) return i;
		}
		return -1;
	} else {
		ll le = 2, ri = x;
		while( le < ri ) {
			ll mid = (le + ri + 1) >> 1, t = x;
			for(int i=1;i<=p;i++) t /= mid;
			
			if( t ) le = mid;
			else ri = mid - 1;
		}
		int c = 0; ll t = x;
		while( t % le == 0 ) t /= le, c++;
		return (c == p && t == 1 ? le : -1);
	}
}

std::vector<int>ans;

bool vis[N + 5]; ll x[N + 5], b[N + 5]; int n, k;
int main() {
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) {
		scanf("%lld", &x[i]);
		for(int j=60;j>=1;j--) {
			ll p = calc(x[i], j);
			if( p != -1 ) {
				if( is_prime(p) ) v[id(b[i] = p)].push_back(i);
				break;
			}
		}
	}
	
	if( k == 1 ) {
		puts("0");
		return 0;
	}
	
	int sum = 0;
	for(int i=1;i<=cnt;i++) if( (int)v[i].size() > 1 )
		sum += (int)(v[i].size());
	if( sum >= k ) {
		int mx = 0;
		for(int i=1;i<=cnt;i++) if( (int)v[i].size() > 1 )
			if( !mx || v[i].size() > v[mx].size() ) mx = i;
		if( (int)v[mx].size() == 2 ) {
			if( k % 2 == 0 ) {
				for(int i=1;i<=cnt;i++) if( (int)v[i].size() > 1 )
					ans.push_back(v[i][0]), ans.push_back(v[i][1]);
			} else {
				for(int i=1;i<=n;i++) if( !b[i] ) {
					ll t = x[i]; int s = 0;
					for(int j=1;j<=cnt;j++) if( (int)v[j].size() > 1 ) {
						if( t % pr[j] == 0 ) s++;
						while( t % pr[j] == 0 ) t /= pr[j];
					}
					if( t == 1 && 2 * s < k ) {
						for(int j=1;j<=cnt;j++) if( (int)v[j].size() > 1 && x[i] % pr[j] == 0 )
							ans.push_back(v[j][0]), ans.push_back(v[j][1]);
						ans.push_back(i);
						for(int j=1;j<=cnt;j++) if( (int)v[j].size() > 1 && x[i] % pr[j] )
							ans.push_back(v[j][0]), ans.push_back(v[j][1]);
						break;
					}
				}
			}
		} else {
			for(int i=1;i<=cnt;i++) if( i != mx && (int)v[i].size() > 1 ) {
				ans.push_back(v[i][0]), ans.push_back(v[i][1]);
				for(int j=2;j<(int)v[i].size();j++) {
					if( (int)ans.size() + (int)v[mx].size() >= k ) break;
					ans.push_back(v[i][j]);
				}
				if( (int)ans.size() + (int)v[mx].size() >= k ) break;
			}
			for(int l=0;l<(int)v[mx].size();l++)
				ans.push_back(v[mx][l]);
		}
	} else {
		for(int i=1;i<=cnt;i++) if( (int)v[i].size() > 1 ) {
			for(auto a : v[i]) ans.push_back(a);
		}
		for(int i=1;i<=n;i++) if( !b[i] ) {
			ll t = x[i];
			for(int j=1;j<=cnt;j++) if( (int)v[j].size() > 1 ) {
				while( t % pr[j] == 0 ) t /= pr[j];
			}
			if( t == 1 ) ans.push_back(i);
		}
	}
	
	if( (int)ans.size() < k ) {puts("0"); return 0;}
	ans.resize(k), std::sort(ans.begin(), ans.end());
	for(int i=0;i<k;i++) printf("%lld%c", x[ans[i]], i + 1 == k ? '\n' : ' ');
}