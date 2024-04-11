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
	map<int, int> mp;
	vt<int> a(5);
	for(int i=0; i < 5; i++)
		cin >> a[i];
	for(int i=0; i < 5; i++)
		mp[a[i]]++;
	int s=0;
	for(int i=0; i < 5; i++)
		s += a[i];
	int mn=INT_MAX-1;

	for(auto c: mp) {
		if(c.second >= 2) {
			mn = min(mn, s - (c.first) * (c.second > 3 ? 3 : c.second));
		}
	}

	cout << (mn == INT_MAX-1? s : mn) << "\n";

}