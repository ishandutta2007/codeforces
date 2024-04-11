#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int M = N * 3;
const int T = 32769;
const double pi = acos(-1);

struct C {
	double x , y;
};

C operator + (C &a , C &b) {return (C){a.x + b.x , a.y + b.y};}
C operator - (C &a , C &b) {return (C) {a.x - b.x , a.y - b.y};}
C operator * (C &a , C &b) {return (C){a.x * b.x - a.y * b.y , a.x * b.y + a.y * b.x};}

int n , m , t , x , stk[N] , MAX , now , A;
C W[T];

//divide and conquer

void DFT(C *A , int up) {
	MAX = 1 << up;
	for(int i = 0;i < MAX / 2;++ i) W[i] = (C){cos(pi * 2 / MAX * i) , sin(pi * 2 / MAX * i)};
	for(int i = 1;i < MAX;++ i) {
		for(register int j = 0;j < up;++ j) if((1 << j) & i) stk[j] = 1; else stk[j] = 0;
		reverse(stk , stk + up);now = 0;
		for(register int j = up - 1;j >= 0;-- j) now = now + stk[j] * (1 << j);
		if(i < now) swap(A[i] , A[now]);
	}
	int mid , L , len;C u , v;
	register int t , j , k; 
	for(t = 0;t < up;++ t) {
		len = 1 << (t + 1);
		len = MAX / len;
		for(j = 0;j < MAX;j += (1 << t + 1)) {
			mid = j + (1 << t);
			for(k = j;k < mid;++ k) {
				v = A[k + (1 << t)] * W[len * (k - j)];
				A[k + (1 << t)] = A[k] - v;A[k] = A[k] + v; 
			}
		}
	}
}

double dp[N][T] , B[M][T];
int to[M] , cnt , Co[M]  , y , z , from[M];

C X[T] , Y[T];
double P[M][T] , PP[M][T];

int len1 , len2 , All , up;

void calc(int who , int L , int R , int l , int r) {
	A = to[who];
	if(R - L <= 1000) {
		register int i , j;
		for(i = l;i <= r;++ i) {
			for(j = L;j <= R;++ j) {
				B[who][i] += P[who][j - i] * dp[A][j];
			}
		}
		return;
	}
	len1 = R - l , len2 = L;
	register int i;
	for(i = 0;i <= len1;++ i) X[i].x = P[who][len1 - i];
	for(i = 0;i <= R - L;++ i) Y[i].x = dp[A][i + L];
	All = len1 + R - L + 1 , up = 0;
	while((1 << up) < All) ++ up;
	DFT(X , up); DFT(Y , up);
	for(i = 0;i < (1 << up);++ i) X[i] = X[i] * Y[i];
	reverse(X + 1 , X + (1 << up));
	DFT(X , up);
	for(i = l;i <= r;++ i) B[who][i] += X[i +len1 - len2].x / (1 << up);
	for(i = 0;i < (1 << up);++ i) X[i].x = X[i].y = Y[i].x = Y[i].y = 0;
}
void get(int x) {
	for(int i = 1;i <= m;++ i) {
		dp[from[i]][x] = min(dp[from[i]][x] , B[i][x] + Co[i]);
	}
}
void solve(int l , int r) {
	if(l == r) {
		get(l); return;
	}
	int mid = (l + r) >> 1;
	solve(mid + 1 , r);
	for(int i = 1;i <= m;++ i)
	calc(i , mid + 1 , r , l , mid);
	solve(l , mid);
}

int dis[N][N];

main(void) {
	//freopen("data.txt" , "r" , stdin);
	int cxt_is_JULAO;
	scanf("%d%d%d%d" , &n , &m , &t , &cxt_is_JULAO);
	for(int i = 1;i <= n;++ i) for(int j = 1;j <= n;++ j) dis[i][j] = 1e9 , dis[i][i] = 0;
	for(int i = 1;i <= m;++ i) {
		scanf("%d%d%d" , &x , & y , &z);
		from[i] = x; to[i] = y; Co[i] = z;
		dis[x][y] = z;
		for(int j = 1;j <= t;++ j) scanf("%lf" , &P[i][j]) , P[i][j] /= 100000.;
	}
	for(int k = 1;k <= n;++ k) {
		for(int i = 1;i <= n;++ i) {
			for(int j = 1;j <= n;++ j) {
				dis[i][j] = min(dis[i][k] + dis[k][j] , dis[i][j]);
			}
		}
	}
	for(int i = 1;i <= n;++ i) {
		for(int j = 0;j <= t;++ j) dp[i][j] = 1e18;
	}
	for(int j = 1;j <= m;++ j)
	for(int i = t;i >= 1;-- i) PP[j][i] = P[j][i] + PP[j][i + 1];
	for(int i = 1;i <= m;++ i) {
		for(int j = 1;j <= t;++ j) {
			B[i][j] += (dis[to[i]][n] + cxt_is_JULAO) * PP[i][t - j + 1]; 
		}
	}
	for(int j = 0;j <= t;++ j) dp[n][j] = 0;
	solve(0 , t);
	printf("%.12lf\n" , dp[1][0]);
}