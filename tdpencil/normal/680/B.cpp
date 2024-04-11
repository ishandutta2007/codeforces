#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vt vector
#define all(x) x.begin(),x.end()
#define ar array
#define sumvt(x) ll(accumulate(all(x), 0LL))
#define sumar(x, n) ll(accumulate(x,x+n,0LL))

template<class T> void read(T &t) {
	cin >> t;
}
template<class T> void read(vt<T> &a) {
	for(auto &i: a) cin >> i;
}
template<class T> void read(vt<pair<T, T>> &a) {
	for(auto &i: a) cin >> i.first >> i.second;
}
template<class T> void read(vt<ar<T, 2>> &a) {
	for(auto &i: a) cin >> i[0] >> i[1];
}
int main() {
	int n, a; cin >> n >> a;

	int ans=0;
	vt<int> c(n);
	for(int i=0; i < n; i++) cin >> c[i];
	int l=(a-1),r=(a-1);

	while(l >= 0 || r < n) {
		if(l < 0) {
			if(c[r] == 1)
				ans++;
		} else if(r >= n) {
			if(c[l] == 1)
				ans++;
		} else {
			if(l != r && c[r] == c[l] && c[r]) {
				ans += 2;
			} else if(l == r) {
				if(c[r] == c[l] && c[r]) ++ans;
			}
		}
		l--;
		r++;
	}
	cout << ans << "\n";
}