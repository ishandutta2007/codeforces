#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n;
long double p[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> p[i];
	long double ans=0, a=0;
	for(int i=0; i<n; ++i) {
		a+=1;
		ans+=a*p[i];
		a*=p[i];
	}
	ans*=2;
	for(int i=0; i<n; ++i)
		ans-=p[i];
	cout << fixed << setprecision(9) << ans;
}