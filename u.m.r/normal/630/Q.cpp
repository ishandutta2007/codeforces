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

double sqr(double x){
	return x * x;
}

int main(){
	ll a, b, c;
	cin>>a>>b>>c;
	double aa = sqrt(a * a - sqr(a / 2.0 / cos(30.0 / 180 * acos(-1))));
	double bb = sqrt(b * b - sqr(b / 2.0 / cos(45.0 / 180 * acos(-1))));
	double cc = sqrt(c * c - sqr(c / 2.0 / cos(54.0 / 180 * acos(-1))));
//	cout<<aa<<bb<<cc<<endl;
	printf("%.20lf\n", 
	aa * (tan(30.0 / 180 * acos(-1)) * a / 2.0) * a / 2.0 * 3 / 3 + 
	bb * (tan(45.0 / 180 * acos(-1)) * b / 2.0) * b / 2.0 * 4 / 3 + 
	cc * (tan(54.0 / 180 * acos(-1)) * c / 2.0) * c / 2.0 * 5 / 3 );
	return 0;
}