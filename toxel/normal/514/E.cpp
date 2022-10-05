#include<bits/stdc++.h>

const int moder = 1000000007;
const int N = 110;

struct matrix{
	
	int a[N][N];
	int n, m;
	
	matrix (int n, int m):n(n), m(m){memset(a, 0, sizeof(a));}
	
	int *operator [] (int i){
		return a[i];
	}
	
	matrix operator * (const matrix &p)const &{
		matrix ret(n, p.m);
		for (int k = 0; k < m; ++ k){
			for (int i = 0; i < n; ++ i){
				for (int j = 0; j < p.m; ++ j){
					ret.a[i][j] = (ret.a[i][j] + 1ll * a[i][k] * p.a[k][j]) % moder;
				}
			}
		}
		return ret;
	}
};

matrix power(matrix a, int exp){
	matrix ret(a.n, a.n);
	for (int i = 0; i < a.n; ++ i){
		ret[i][i] = 1;
	}
	for ( ; exp; exp >>= 1){
		if (exp & 1){
			ret = ret * a;
		}
		a = a * a;
	}
	return ret;
}

int cnt[N];

int main(){
	int n, x;
	scanf("%d%d", &n, &x);
	for (int i = 0, y; i < n; ++ i){
		scanf("%d", &y);
		++ cnt[y];
	}
	matrix trans(101, 101);
	trans[0][0] = 1;
	for (int i = 1; i < 100; ++ i){
		trans[i][i + 1] = 1;
	}
	for (int i = 1; i <= 100; ++ i){
		trans[100][101 - i] = cnt[i];
	}
	trans[100][0] = 1;
	trans = power(trans, x);
	return printf("%d\n", (trans[100][0] + trans[100][100]) % moder), 0;
}