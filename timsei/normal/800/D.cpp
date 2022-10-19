#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define int long long

const int mod = 1e9 + 7;
const int i2 = mod / 2 + 1;

#define lowbit(x) (x & (-x))

int Sq[N] , S[N], n , m , x , y , a[N] , num[N] , ans[N] , ans2[N];
int U[] = {1 , 10 , 100 , 1000 , 10000 , 100000 , 1000000};

void add(int &x, int y) {
    x += y; x %= mod;
}

void sub(int &x , int y) {
    x -= y; x %= mod; if(x < 0) x += mod;
}

int bc(int x) {
    int res = 0;
    while(x) {
	++ res; x -= lowbit(x);
    }
    return res;
}

int Inc[23333] , B[2333];

int Pow(int x , int y){
    if(y < 0) return 0;
    if(!x) return 0;
    if(y == 0) return 1;
    if(y == 1) return x % mod;
    int it = Pow(x , y >> 1);
    it = it * it % mod;
    if(y & 1) it = it * x % mod;
    return it;
}

signed main(void) {
    for(int i = scanf("%lld" , &n);i <= n;++ i) scanf("%lld" , &a[i]) , add(S[a[i]] , a[i]) , add(Sq[a[i]] , a[i]* a[i]) , ++ num[a[i]];
    for(int i = 1;i < (1 << 6);++ i) {
	for(int j = 0;j < 6;++ j) if((1 << j) & i) Inc[i] += U[j];
	B[i] = bc(i);
    }
    int now = 0;
    for(int i = 999999;i >= 0;-- i) {
	int NOT = 0;
	for(int j = 0;j < 6;++ j) {
	    int xxy = i;
	    xxy %= U[j + 1];
	    xxy /= U[j];
	    if(xxy == 9) NOT |= (1 << j);
	}
	for(int j = 1;j < (1 << 6);++ j) if((j & NOT) == 0){
	    int ano = i + Inc[j]; if(ano > 999999) continue;
	    if(B[j] & 1) add(S[i] , S[ano]) , add(Sq[i] , Sq[ano]) , add(num[i] , num[ano]) , sub(ans[i] , ans2[ano]);
	    else sub(S[i] , S[ano]) , sub(Sq[i] , Sq[ano]) , sub(num[i] , num[ano])  , add(ans[i] , ans2[ano]);
	}
	int res = S[i] * S[i] % mod + Sq[i];
	res = res % mod * i2 % mod;
	res = Pow(2 , num[i] - 1) * res % mod;
	ans2[i] = res; add(ans[i] , ans2[i]);
	now ^= (ans[i] * i);
    }
    cout << now;
}