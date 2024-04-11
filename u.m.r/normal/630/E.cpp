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
	ll x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	ll x = (x2 - x1) / 2 + 1;
	ll ans = 0;
	if ((x2 - x1) % 2){
		ans = x * (y2 - y1 + 1);
	} 
	else{
		if ((y2 - y1 + 1) % 2)
			ans = (y2 - y1 + 1) / 2 * (2 * x - 1) + x;
		else
			ans = (y2 - y1 + 1) / 2 * (2 * x - 1);
	}
	cout<<ans<<endl;
	return 0;
}