#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e4 + 5;
const int Base = N;
const int MAX = 1e4;

int A[N] , n , m , x , y , tmp[N * 2] , tmp2[N * 2] , S[N] , f[N * 2] , a[N * 2] , b[N * 2];

int ans = 0;

void solve(int l , int r) {
	if(l >= r) {
		return;
	}
	int mid = (l + r) >> 1;
	int Sl = S[mid - 1] - S[l - 1] , Sr = S[r] - S[mid - 1];
	
	tmp[0 + Base] = 1;
	
	for(int i = mid - 1;i >= l;-- i) {
		for(int j = - Sl;j <= Sl;++ j) f[j + Base] = 0;
		for(int j = - Sl;j <= Sl - A[i];++ j) {
			f[j + A[i] + Base] += tmp[j + Base];
			if(f[j + A[i] + Base] >= mod) f[j + A[i] + Base] -= mod;
		}
		for(int j = - Sl + A[i];j <= Sl;++ j) {
			f[j - A[i] + Base] += tmp[j + Base];
			if(f[j - A[i] + Base] >= mod) f[j - A[i] + Base] -= mod;
		}
		for(int j = - Sl;j <= Sl;++ j) {
			a[j + Base] = (a[j + Base] + tmp[j + Base]) % mod;
			tmp[j + Base] = f[j + Base] % mod;
		}
	}
	
	for(int i = - Sl;i <= Sl;++ i) a[i + Base] = (a[i + Base] + tmp[i + Base]) % mod;
	
	tmp2[A[mid] + Base] = 1;
	tmp2[-A[mid] + Base] = 1;
	
	
	for(int i = mid + 1;i <= r;++ i) {
		for(int j = - Sr;j <= Sr;++ j) f[j + Base] = 0;
		for(int j = - Sr;j <= Sr - A[i];++ j) {
			f[j + A[i] + Base] += tmp2[j + Base];
			if(f[j + A[i] + Base] >= mod) f[j + A[i] + Base] -= mod;
		}
		for(int j = - Sr + A[i];j <= Sr;++ j) {
			f[j - A[i] + Base] += tmp2[j + Base];
			if(f[j - A[i] + Base] >= mod) f[j - A[i] + Base] -= mod;
		}
		for(int j = - Sr;j <= Sr;++ j) {
			b[j + Base] = (b[j + Base] + tmp2[j + Base]) % mod;
			tmp2[j + Base] = f[j + Base];
		}
	}
	
	for(int i = - Sr;i <= Sr;++ i) b[i + Base] = (b[i + Base] + tmp2[i + Base]) % mod;
		
//	cerr << mid << endl;
//	for(int i = - Sl;i <= Sl;++ i) cerr << a[i + Base] <<" ";
//	puts("");
//	for(int i = - Sr;i <= Sr;++ i) cerr << b[i + Base] <<" ";
//	puts("");
	
	for(int i = - Sl;i <= Sl;++ i) {
		ans += a[i + Base] * 1LL * b[-i + Base] % mod;
		ans %= mod;
	}
	
	for(int i = - Sl;i <= Sl;++ i) tmp[i + Base] = a[i + Base] = 0;
	for(int i = - Sr;i <= Sr;++ i) tmp2[i + Base] = b[i + Base] = 0;
	
	solve(l , mid - 1); solve(mid + 1 , r);
}

main(void) {
	scanf("%d" , &n);
	for(int i = 1;i <= n;++ i) 
	scanf("%d" , &A[i]) , S[i] = S[i - 1] + A[i];
	solve(1 , n);
	cout << ans;
}