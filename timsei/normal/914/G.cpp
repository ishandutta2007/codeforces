#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 5;
const int MAX = (1 << 17) + 1;
const int now = MAX - 1;

int A[MAX] , n , m , x , y , fib[MAX] , S1[MAX] , S2[MAX] , S3[MAX] , a[N];

const int mod = 1e9 + 7;
const int inv2 = mod / 2 + 1;

void step1(void) { // 3 ^ n
    for(int i = 0;i < now;++ i) {
	for(int j = i;j;j = (j - 1) & i) {
	    S1[i] += (A[j] * 1ll * A[i ^ j]) % mod;
	    S1[i] %= mod;
	}
	S1[i] = (S1[i] % mod + A[0] * 1ll * A[i] % mod) % mod;
    }
    for(int i = 0;i < now;++ i) S1[i] *= fib[i] , S1[i] %= mod;
}

void FWT(int *B , int ty , int rev) {
    for(int i = 1;i < now;i <<= 1) {
	for(int j = 0;j < now;j += i << 1) {
	    for(int k = j;k <= j + i - 1;++ k) {
		int a = B[k] , b = B[k + i];
		if(ty == 1 && !rev) {
		    B[k] = (a + b) % mod;
		    B[k + i] = (a - b + mod) % mod;
		}
		if(!ty && !rev) {
		    B[k] = (a + b) % mod;
		}
		if(ty == 1 && rev) {
		    B[k] = (a + b) % mod * 1ll * inv2 % mod;
		    B[k + i] = (a - b + mod) % mod * 1ll * inv2 % mod;
		}
		if(!ty && rev) {
		    B[k] = (a - b + mod) % mod;
                }
	    }
	}
    }
}

void debug(int * B) {
    return;
    for(int i = 0;i < now;++ i) if(B[i]) cerr << i <<" "<< B[i] << endl;
    puts("------------------dress Like a day Dream");
}

main(void) {
    fib[0] = 0; fib[1] = 1; for(int i = 2;i < MAX;++ i) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    cin >> n;
    for(int i = 1;i <= n;++ i) cin >> a[i] , S2[a[i]] += fib[a[i]] , ++ A[a[i]] , S2[a[i]] %= mod;
    step1();
    for(int i = 0;i < now;++ i) S3[i] = A[i];
    FWT(S3 , 1 , 0);
    for(int i = 0;i < now;++ i) S3[i] = (S3[i] % mod * 1ll * S3[i] % mod) % mod;
    FWT(S3 , 1 , 1);
    for(int i = 0;i < now;++ i) S3[i] = S3[i] * 1ll * fib[i] % mod;
    debug(S1); debug(S2); debug(S3);
    FWT(S1 , 0 , 0); FWT(S2 , 0 , 0); FWT(S3 , 0 , 0);
    for(int i = 0;i < now;++ i) S3[i] = (S3[i] * 1ll * S2[i]) % mod * S1[i] % mod;
    FWT(S3 , 0 , 1);
    int ans = 0;
    for(int i = 0;i < 17;++ i) (ans += S3[1 << i]) %= mod;
    debug(S3);
    cout << ans;
}