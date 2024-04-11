#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const long long MOD = 1000000007;

long long k, l, a;
char s[100005];
vector<long long> v;

long long get2(long long k) {
	if (k == 0) return 1;
	if (k == 1) return 2;
	long long t = get2(k / 2);
	if (k % 2 == 1) return t * t % MOD * 2 % MOD; else return t * t % MOD;
}

long long get2_mul(long long k) {
	if (k == 0) return 1;
	if (k == 1) return (1 + get2(l)) % MOD;
	long long t = get2_mul((k - 1) / 2);
	if (k % 2 == 0) {
	  return ((t + t * get2(l * (k / 2)) % MOD) % MOD + get2(l * k)) % MOD;
	} else {
		return (t + t * get2(l * (k / 2 + 1)) % MOD) % MOD;
	}
}


int main() {
	scanf("%s", s);
	cin >> k;
	for (int i = 0; s[i]; ++i) {
	  if (s[i] == '0' || s[i] == '5') {
	    v.push_back(1);
		} else {
		  v.push_back(0);
		}
	}
	l = v.size();
	long long a = 0, mul = 1;
	for (int i = 0; i < l; ++i) {
	  a += mul * v[i];
	  a %= MOD;
	  mul = (mul * 2) % MOD;
	}
	//for (int i = 1; i <= 50; ++i) cout << get2_mul(i - 1) << endl;
	cout << a * get2_mul(k - 1) % MOD << endl;
	return 0;
}