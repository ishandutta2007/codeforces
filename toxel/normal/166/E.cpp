#include<bits/stdc++.h>

const int moder = 1e9 + 7;

struct matrix{
	static const int N = 4;
	
	int a[N][N];
	
	matrix (){memset(a, 0, sizeof(a));}
	
	int * operator [] (int n){return a[n];}
	
	matrix operator * (const matrix &m)const{
		matrix ret;
		for (int k = 0; k < N; ++ k){
			for (int i = 0; i < N; ++ i){
				for (int j = 0; j < N; ++ j){
					ret.a[i][j] = (ret.a[i][j] + 1ll * a[i][k] * m.a[k][j]) % moder;
				}
			}
		}
		return ret;
	}
};

matrix power(matrix a, int exp){
	matrix ret;
	for (int i = 0; i < 4; ++ i){
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

int main(){
	int n;
	scanf("%d", &n);
	matrix trans;
	for (int i = 0; i < 4; ++ i){
		for (int j = 0; j < 4; ++ j){
			if (i != j) trans[i][j] = 1;
		}
	}
	trans = power(trans, n);
	printf("%d\n", trans[0][0]);
	return 0;
}