#include"bits/stdc++.h"
using namespace std;

typedef long long LL;
LL n,k;

LL phi (LL n){
	LL res = 1;
	for (int i=2; 1ll*i*i<=n; i++){
		if (n%i==0){
			res = res * (i-1), n /= i;
			while (n % i == 0)
				res = res * i, n /= i;
		}
	}
	if (n > 1) res *= n-1;
	return res;
}

int main(){
	cin>>n>>k;
	while (k > 0 && n != 1){
		n = phi(n);
		k -= 2;
	}
	cout << n%1000000007 << endl;
	return 0;
}