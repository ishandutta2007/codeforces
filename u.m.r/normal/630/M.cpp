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
	ll ret = 1;
	for(; q; q >>= 1){
		if (q & 1)
			ret = ret * p % MM;
		p = p * p % MM;
	}
	return ret;
}

ll getInv(ll p){
	return pw(p, MM - 2);
}

int main(){
	ll n;
	cin>>n;
	n %= 360;
	n += 360;
	n %= 360;
	int ans = 1000, cnt = 0;
	for(int i = 0; i <= 13; i++){
	//	cout<<i<<' '<<n<<' '<<ans<<endl;
		if (n < ans){
			cnt = i;
			ans = n;
		}
		if (360 - n < ans){
			cnt = i;
			ans = 360 - n;
		}
		n = (n + 270) % 360;
	}
	cout<<cnt<<endl;
	return 0;
}