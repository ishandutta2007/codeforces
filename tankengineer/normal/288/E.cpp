#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const long long MOD = 1000000007;

const int LL = 2000005, L = 1000005;

int l;
long long two[LL], ten[LL][3], ften[LL][3], fsum[LL], fans[LL], nmod[LL], nsum[LL], ncal[LL];

char ls[LL], rs[LL];

void init() {
	//two 2 ^ n % MOD
	two[0] = 1;
	for (int i = 1; i <= L; ++i) two[i] = two[i - 1] * 2 % MOD;
	//ten x * 10 ^ (n - 1) % MOD
	ten[1][0] = 1;
	for (int i = 2; i <= L; ++i) ten[i][0] = ten[i - 1][0] * 10 % MOD;	
	for (int i = 1; i <= L; ++i) ten[i][1] = ten[i][0] * 4 % MOD;
	for (int i = 1; i <= L; ++i) ten[i][2] = ten[i][0] * 7 % MOD;
	//ften xxx...x % MOD
	ften[0][0] = 0;
	for (int i = 1; i <= L; ++i) ften[i][0] = (ften[i - 1][0] + ten[i][0]) % MOD;
	for (int i = 1; i <= L; ++i) ften[i][1] = ften[i][0] * 4 % MOD;
	for (int i = 1; i <= L; ++i) ften[i][2] = ften[i][0] * 7 % MOD;
	//fsum (444...4 + ... + 777...7) % MOD
	fsum[0] = 0;
	for (int i = 1; i <= L; ++i) fsum[i] = (fsum[i - 1] * 2 % MOD + (ten[i][1] + ten[i][2]) * two[i - 1] % MOD) % MOD;
	//fans que(777...7)
	fans[0] = 0;
	fans[1] = 28;
	for (int i = 2; i <= L; ++i) {
		//444...4 - 744...4
		fans[i] = ten[i][1] * ten[i][1] % MOD * ((two[i - 1] - 1 + MOD) % MOD) % MOD +
			ten[i][1] * ((2 * fsum[i - 1] - ften[i - 1][1] - ften[i - 1][2] + MOD * 2) % MOD) % MOD +
			fans[i - 1];
		fans[i] %= MOD;
		//477...7 - 744...4
		fans[i] = (fans[i] + (ten[i][1] + ften[i - 1][2]) % MOD * ((ten[i][2] + ften[i - 1][1]) % MOD) % MOD) % MOD;
		//744...4 - 777...7
		fans[i] = fans[i] + 
			ten[i][2] * ten[i][2] % MOD * ((two[i - 1] - 1 + MOD) % MOD) % MOD +
			ten[i][2] * ((2 * fsum[i - 1] - ften[i - 1][1] - ften[i - 1][2] + MOD * 2) % MOD) % MOD +
			fans[i - 1];	
		fans[i] %= MOD;
	}
}

long long quec(char *n, int st) {
	if (st == l) return 0;
	int i = l - st;
	long long ret = 0;
	if (n[st] == '4') {
		ret = ten[i][1] * ten[i][1] % MOD * ((nmod[i - 1] - 1 + MOD) % MOD) % MOD +
			ten[i][1] * ((2 * nsum[i - 1] - ften[i - 1][1] - ncal[i - 1] + MOD * 2) % MOD) % MOD +
			quec(n, st + 1);
		ret %= MOD;
	} else {
		ret = ten[i][1] * ten[i][1] % MOD * ((two[i - 1] - 1 + MOD) % MOD) % MOD +
			ten[i][1] * ((2 * fsum[i - 1] - ften[i - 1][1] - ften[i - 1][2] + MOD * 2) % MOD) % MOD +
			fans[i - 1];
		ret %= MOD;
		ret = (ret + (ten[i][1] + ften[i - 1][2]) % MOD * ((ten[i][2] + ften[i - 1][1]) % MOD) % MOD) % MOD;
		ret = ret +
			ten[i][2] * ten[i][2] % MOD * ((nmod[i - 1] - 1 + MOD) % MOD) % MOD +
			ten[i][2] * ((2 * nsum[i - 1] - ften[i - 1][1] - ncal[i - 1] + MOD * 2) % MOD) % MOD +
			quec(n, st + 1);
		ret %= MOD;    			
	}
	return ret;
}

long long que(char *n) {
	//nmod
	memset(nmod, 0, sizeof(nmod));
	nmod[0] = 1;
	int cnt = 0;
	for (int i = l - 1; i >= 0; --i) {
		++cnt;
		if (n[i] == '4') {
			nmod[cnt] = nmod[cnt - 1];
		} else {
			nmod[cnt] = (nmod[cnt - 1] + two[cnt - 1]) % MOD;
		}
	}
	//nsum
	memset(nsum, 0, sizeof(nsum));
	cnt = 0;
	for (int i = l - 1; i >= 0; --i) {
		++cnt;
		if (n[i] == '4') {
			nsum[cnt] = (nsum[cnt - 1] + ten[cnt][1] * nmod[cnt - 1] % MOD) % MOD;
		} else {
			nsum[cnt] = (nsum[cnt - 1] + ten[cnt][2] * nmod[cnt - 1] % MOD + fsum[cnt - 1] + ten[cnt][1] * two[cnt - 1] % MOD) % MOD;
		}
	}
	//ncal
	memset(ncal, 0, sizeof(ncal));
	cnt = 0;
	for (int i = l - 1; i >= 0; --i) {
		++cnt;
		if (n[i] == '4') {
			ncal[cnt] = (ncal[cnt - 1] + ten[cnt][1]) % MOD;
		} else {
			ncal[cnt] = (ncal[cnt - 1] + ten[cnt][2]) % MOD;
		}
	}
	return quec(n, 0);
}

int main() {
	scanf("%s %s", ls, rs);
	l = strlen(ls);
	init();
	long long ans1 = que(ls), ans2 = que(rs);
	cout << (ans2 - ans1 + MOD) % MOD << endl;
	return 0;
}