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
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = (x * x) % mod;
	if(e&1) x = (x * a) % mod;
	return x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, K;
	cat A, B, mod = 1000000009;
	cin >> N >> A >> B >> K;
	cat fr1 = (B * pw(A, mod-2, mod)) % mod;
	cat fr2 = pw(fr1, K, mod);
	string S;
	cin >> S;
	cat sum = 0;
	for(int i = K-1; i >= 0; i--) sum = (sum * fr1 + (S[i] == '+' ? 1 : -1)) % mod;
	sum = (sum * pw(A, N, mod)) % mod;
	cat sum2 = pw(fr2, (N+1)/K, mod) - 1;
	if((fr2-1) % mod == 0) sum2 = (N+1)/K;
	else sum2 = (sum2 * pw(fr2-1, mod-2, mod)) % mod;
	sum2 %= mod;
	cat ans = sum2 * sum % mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
	// sum_j sum_i=0^K-1 s[i] A^(N-K*j-i) B^(K*j+i) = sum_j sum_i=0^K-1 s[i] (B/A)^(i) A^(N-K*j) B^(K*j) = s A^N sum_j (B/A)^K*(0..(N+1)/K-1)
	return 0;}

// look at my code
// my code is amazing