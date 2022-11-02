#include <bits/stdc++.h>

using namespace std;

#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define fi0(x) memset((x), 0, sizeof(x))
#define ins insert
#define ret return
#define cont continue

typedef long long int lint;

lint binpow(lint a, lint n, lint mod){
	lint res = 1;
	while(n){
		if(n&1){
			res = (res*a)%mod;
		}
		a = (a * a)%mod;
		n >>= 1;
	}
	ret res;
}

const int KEK = 2e6;
lint fac[KEK];
lint inv(lint a, lint mod){
	ret binpow(a, mod - 2, mod);
}

lint phi = 1;

lint C(lint a, lint b){
	if(b > a)ret 0;
	lint z = fac[a - b] * fac[b] % phi;
	ret fac[a] * inv(z, phi) % phi;
}

lint n, m, a, q;

lint ans[KEK];



int main(){
	//freopen("t.in", "r", stdin);
	scanf("%lld%lld%lld%lld", &n, &m, &a, &q);
	int cq = q;
	for(lint i = 2; i * i <= q; i++){
		if(cq%i != 0)cont;
		lint pw = 0;
		while(cq%i == 0){pw++; cq /= i;}
		lint cp = 1;
		F(j, 0, pw)cp *= i;
		lint d = cp - cp/i;
		phi *= d;
	}
	if(cq != 1)phi *= cq - 1;
	lint ord = phi;
	for(lint i = 2; i * i <= phi; i++){
		if(phi%i != 0)cont;
		lint j = phi/i;
		if(binpow(a, i, q) == 1)ord = min(ord, i);
		if(i != j && binpow(a, j, q) == 1)ord = min(ord, j);
	}
	swap(ord, phi);
	fac[0] = 1;
	F(i, 1, m + 1)fac[i] = fac[i - 1] * i % phi;
	ans[0] = a % q;
	lint old = 1;
	F(i, 1, n){
		lint delta = C(m, i);
		//printf("delta = %d\n", delta);
		old = (old + delta)%phi;
		//printf("old = %d\n", old);
		ans[i] = binpow(a, old, q);
	}
	Df(i, n - 1, -1)printf("%lld ", ans[i]);
}