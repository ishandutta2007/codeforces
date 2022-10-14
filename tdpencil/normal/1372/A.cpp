#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
#define vt vector
#define pb push_back
const int mxN = 2e5;
vector<ll> sieve(ll x) {
	assert(x<=100000);
	bool prime[x+1];
	memset(prime, 0, sizeof(prime));
	vector<ll> temp;
	for(int p = 2; p*p<=x; p++){
		
		if(prime[p]){
			for(int i = p*p; i<=x; i+=p) {
				prime[i]=false;
			}
		}
	}
	for(int p = 2; p<=x; p++) {
		if(prime[p])
			temp.push_back(p);
	}
	return temp;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	while(n--){
		ll a;
		cin >> a;
		for(int i =0; i < a; i++) {
			cout << "1 ";
		}
		cout << '\n';
	}
}