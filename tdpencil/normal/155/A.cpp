#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define vll vector<long long>
int main() {
	ll b;
	cin >> b;
	vector<ll> performances(b);
	ll record;
	for(int i =0; i < b; i++) cin >> performances[i];
	ll worst, best;
	ll ans =0;
	worst=performances[0];
	best=performances[0];
	for(int i =1; i < b; i++) {
		if(performances[i]>worst) {
			++ans;
			worst=performances[i];
		}
		if(performances[i]<best) {
			++ans;
			best=performances[i];
		}
	}
	printf("%lld\n", ans);
}