//Submitting someone else's code so that Lockout bot knows I tested this contest

#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MOD = 1e9+7;

int n;
int res,fact;

signed main(){
	cin >> n;
	res = 1;
	fact = 1;
	for(int i = 1;i <= n-1;i++){
		res *= 2;
		fact *= i;
		fact %= MOD;
		res %= MOD;
	}
	fact *= n;
	fact %= MOD;
	fact -= res;
	fact %= MOD;
	if(fact < 0)fact += MOD;
	cout << fact;
	return 0;
}