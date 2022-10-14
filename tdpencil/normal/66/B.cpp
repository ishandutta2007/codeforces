#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vt vector
#define all(x) x.begin(),x.end()
#define ar array
#define sumvt(x) ll(accumulate(all(x), 0LL))
#define sumar(x, n) ll(accumulate(x,x+n,0LL))

template<class T> void read(T t) {
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
	int n; cin >> n;
	vt<int> a(n);
	read(a);
	int ans=0;
	for(int i=0; i < n; i++) {
		int t=0;
	
		int j=i,k=i;
		int d=0;
		int prevf=a[i];
		int prevs=a[i];
		while( j>=0 || k < n) {
			if(j >= 0 && a[j] <= prevf) {
				prevf = a[j];
				j--;
				continue;
			}
			if(k < n && a[k] <= prevs) {
				prevs = a[k];
				k++;
				continue;
			}
			break;
		}
		j++;
		k--;
		d=(k-j+1);
		ans = max(ans, d);
	}
	cout << ans << "\n";

}