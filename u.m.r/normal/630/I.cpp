#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

ll gcd(ll p, ll q){
	return q ? gcd(q, p % q) : p;
}

ll pw(ll p, ll q){
	if (q < 0)
		return 0;
	ll ret = 1;
	for(; q; q >>= 1){
		if (q & 1)
			ret = ret * p;
		p = p * p;
	}
	return ret;
}

ll getInv(ll p){
	return pw(p, MM - 2);
}

int main(){
	int n;
	cin>>n;
	ll ans = (n - 3) * 4 * 9 * pw(4, n - 4) + 2 * 4 * 3 * pw(4, n - 3);
	cout<<ans<<endl;
	return 0;
}