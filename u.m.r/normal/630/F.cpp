#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e3 + 10;
const int MM = 1e9 + 7;

long long C[MAXN][MAXN];

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

void comb(int n){
	C[0][0] = 1;
	for(int i = 1; i <= n; i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
}

int main(){
	int n;
	cin>>n;
	comb(n);
	cout<<C[n][5]+C[n][6]+C[n][7]<<endl;
	return 0;
}