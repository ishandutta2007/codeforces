#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

long long mem[100][30005];

int m;

int cnt[12], next[12], prec[12]; 
long long pow[12], hash;

void use(int i) {
	hash -= pow[i];
	if ((--cnt[i]) == 0) {
		next[prec[i]] = next[i];
		prec[next[i]] = prec[i];
	}
}

void reuse(int i) {
	hash += pow[i];
	if ((++cnt[i]) == 1) {
		next[prec[i]] = i;
		prec[next[i]] = i;
	}
}

long long go(int mod) {
	if (mem[mod][hash] != -1) {
		return mem[mod][hash];
	}
	long long ret = 0;
	int sum = 0;
	for (int i = next[0]; i <= 11; i = next[i]) {
		sum += cnt[i];
		if (cnt[i]) {
			use(i);
			ret += go((mod * 10 + i - 1) % m);
			reuse(i);
		}
	}
	if (sum == 0 && mod == 0) {
		ret = 1;
	}
	return mem[mod][hash] = ret;
}

int main() {
	memset(mem, -1, sizeof(mem));
	long long d;
	for (int i = 0; i < 12; ++i) {
		next[i] = i + 1;
		prec[i] = i - 1;
	}
	cin >> d >> m;
	while (d) {
		cnt[d % 10 + 1]++;
		d /= 10;	
	}
	pow[0] = 1;
	for (int i = 1; i < 11; ++i) {
		pow[i] = pow[i - 1] * (cnt[i - 1] + 1);
		hash += (long long)cnt[i] * pow[i];
	}
	for (int i = 1; i < 11; ++i) {
		if (cnt[i] == 0) {
			next[prec[i]] = next[i];
			prec[next[i]] = prec[i];
		}
	}
	long long ans = 0;
	for (int i = 2; i <= 10; ++i) {
		if (cnt[i]) {
			use(i);
			ans += go((i - 1) % m);
			reuse(i);
		}
	}
	cout << ans << endl;
	return 0;
}