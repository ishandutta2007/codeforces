#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back 
const int N = 5; 
const int oo = 0x3f3f3f3f; 

struct val{
	int f[N][N];
	val() {}
	val(char c) {
		for (int i = 0; i < N; ++i) 
			for (int j = 0; j < N; ++j) 
				f[i][j] = oo; 
		for (int i = 0; i < N; ++i) f[i][i] = 0; 
		if (c == '2') {
			f[0][1] = 0; 
			f[0][0] = 1; 
		}
		if (c == '0') {
			f[1][2] = 0; 
			f[1][1] = 1; 
		}
		if (c == '1') {
			f[2][3] = 0; 
			f[2][2] = 1; 
		}
		if (c == '7') {
			f[3][4] = 0; 
			f[3][3] = 1; 
		}
		if (c == '6') {
			//f[3][5] = 0; 
			f[3][3] = 1; 
			f[4][4] = 1; 
			//f[4][5] = 0; 
		}
	}
	val operator+(val b) {
		val ret; 
		for (int i = 0; i < N; ++i) 
			for (int j = 0; j < N; ++j) 
				ret.f[i][j] = oo; 
		for (int i = 0; i < N; ++i) 
			for (int j = i; j < N; ++j) 
				for (int k = i; k <= j; ++k) 
					ret.f[i][j] = min(ret.f[i][j], f[i][k]+b.f[k][j]); 
		return ret; 
	}
};

const int maxn = 200006; 
char s[maxn]; 

struct Seg {
	val e[maxn*4];
	void build(int T, int l, int r) {
		if (l == r) {
			e[T] = val(s[l]); 
			return; 
		}
		int m = (l + r) / 2; 
		build(T*2, l, m); build(T*2+1, m+1, r); 
		e[T] = e[T*2]+e[T*2+1]; 
	}
	val ask(int T, int l, int r, int a, int b) {
		if (a <= l && b >= r) return e[T]; 
		int m = (l + r) / 2; 
		val ret('*'); 
		if (a <= m) ret = ret + ask(T*2,l,m,a,b); 
		if (b > m) ret = ret + ask(T*2+1,m+1,r,a,b); 
		return ret; 
	}
}T; 

int n, m; 

int main() {
	scanf( "%d%d", &n, &m ); 
	scanf( "%s", s+1 ); 
	T.build(1,1,n); 
	for (int i = 1; i <= m; ++i) {
		int a, b; 
		scanf( "%d%d", &a, &b ); 
		val res = T.ask(1,1,n,a,b); 
		//for (int i = 0; i < N; ++i) {
			//for (int j = 0; j < N; ++j) printf( "%d ", res.f[i][j] ); 
			//printf( "\n" ); 
		//}
		if (res.f[0][4] > n) puts( "-1" ); 
		else printf( "%d\n", res.f[0][4] ); 
	}
}