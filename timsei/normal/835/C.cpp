#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 201;
const int Q = 200001;

#define int long long

int n , q , c ,  M[N][N] ;
int x[Q] , y[Q] , s[Q];
int S[15][N][N]; 
int tt ,xx1,yy1,xx2,yy2;

void read() {
	scanf("%lld%lld%lld",&n,&q,&c);
	for(int i = 1;i <= n ;i ++) {
		scanf("%lld%lld%lld",&x[i],&y[i],&s[i]);
	}
	memset(S,0,sizeof(S));
	for(int i = 0;i <= c;i ++) {
		memset(M , 0 ,sizeof(M));
		for(int j = 1;j <= n;j ++) {
			M[x[j]][y[j]] += s[j];
			s[j] ++; s[j] = (s[j] % (c + 1));
		}
		for(int j = 1;j <= 100;j ++) {
			for(int k = 1;k <= 100;k ++) {
				S[i][j][k] = S[i][j - 1][k];
				for(int p =1;p <= k;p ++) S[i][j][k] += M[j][p];
			}
		}
	}
	for(int i  = 1;i <=q;i ++) {
		scanf("%lld%lld%lld%lld%lld",&tt,&xx1,&yy1,&xx2,&yy2);
		tt %=(c + 1);
		int ans = 0;
		ans = S[tt][xx2][yy2] - S[tt][xx1 - 1][yy2] -S[tt][xx2][yy1 - 1] + S[tt][xx1- 1][yy1 - 1];
		printf("%lld\n",ans);
	}
}

main() {
	read();
}