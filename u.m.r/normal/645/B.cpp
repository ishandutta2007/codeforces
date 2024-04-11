#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const double eps = 1e-9;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

char s[MAXN];

int main(){
	ll n, k;
	cin>>n>>k;
	if (n / 2 > k){
		cout<< k * k + 2 * (n - 2 * k) * k + k * (k - 1)<<endl;
	}
	else{
		cout<<n * (n - 1) / 2<<endl;
	}
	return 0;
}