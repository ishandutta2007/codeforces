#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define ar array
#define vt vector
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

typedef unsigned long long ull;
const int mxN = 2e5;

int main() {
	int n; cin >> n;
	vi a(n);
	for(auto &i : a)
		cin >> i;

	sort(all(a));
	if(a[n-3]+a[n-2]>a[n-1])
	{
		cout << "YES\n";
		cout << a[n-3] << " " << a[n-1] << " " << a[n-2] << " ";
		for(int i = n - 4; i >= 0; --i)
			cout << a[i] << " ";
	} else {
		cout << "NO\n";
	}
}