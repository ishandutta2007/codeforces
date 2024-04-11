#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890123456789LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

cat mod = 998244353;

cat pw(cat a, cat e) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2);
	x = x * x % mod;
	if(e&1) x = x * a % mod;
	return x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, K;
	cin >> N >> K;
	if(K == 1) {
		cout << "0\n";
		return 0;
	}
	vector<int> H(N);
	for(int i = 0; i < N; i++) cin >> H[i];
	int cnt_dif = 0;
	for(int i = 0; i < N; i++) if(H[i] != H[(i+1)%N]) cnt_dif++;
	if(cnt_dif == 0) {
		cout << "0\n";
		return 0;
	}
	vector<cat> fac(N+1, 1), inv(N+1, 1), K_pw(N+1, 1), inv_K_pw(N+1, 1);
	inv_K_pw[1] = pw(K-2, mod-2);
	K_pw[1] = K-2;
	for(int i = 1; i <= N; i++) {
		fac[i] = i * fac[i-1] % mod;
		inv[i] = pw(i, mod-2) * inv[i-1] % mod;
	}
	for(int i = 2; i <= N; i++) inv_K_pw[i] = inv_K_pw[i-1] * inv_K_pw[1] % mod;
	for(int i = 2; i <= N; i++) K_pw[i] = K_pw[i-1] * K_pw[1] % mod;
	// cat ans = pw(2+inv_K_pw[1], cnt_dif);
	// for(int i = 0; i <= cnt_dif/2; i++) {
	// 	cat C = fac[cnt_dif] * inv[i] % mod * inv[i] % mod * inv[cnt_dif-2*i] % mod;
	// 	ans = (ans - C * inv_K_pw[2*i]) % mod;
	// }
	// ans = (ans * pw(2, mod-2)) % mod * K_pw[cnt_dif] % mod;
	cat ans = 0;
	if(K == 2) {
		for(int i = 0; 2*i < cnt_dif; i++)
			ans = (ans + inv[i] * inv[cnt_dif-i] % mod * fac[cnt_dif]) % mod;
	}
	else {
		for(int i = 0; i <= cnt_dif; i++) for(int j = i+1; j <= cnt_dif-i; j++)
			ans = (ans + inv[i] * inv[j] % mod * inv[cnt_dif-i-j] % mod * inv_K_pw[i+j]) % mod;
		ans = (ans * fac[cnt_dif]) % mod * K_pw[cnt_dif] % mod;
	}
	for(int i = 0; i < N-cnt_dif; i++) ans = ans * K % mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";

	// C(cnt_dif, i) moznosti ako vybrat spravne; C(cnt_dif-i, j > i) ako vybrat nespravne
	// sum cnt_dif! / i! / j! / (cnt_dif-i-j)! * 1/(K-2)**(i+j) * K**(N-cnt_dif) * (K-2)**cnt_dif
	// kde j > i
	// = sum cnt_dif! / i! / j! / (cnt_dif-i-j)! * 1/(K-2)**(i+j) * K**(N-cnt_dif) * (K-2)**cnt_dif 
	// - sum cnt_dif! / i! / i! / (cnt_dif-2*i)! * 1/(K-2)**(i+i) * K**(N-cnt_dif) * (K-2)**cnt_dif
	return 0;
}

// look at my code
// my code is amazing