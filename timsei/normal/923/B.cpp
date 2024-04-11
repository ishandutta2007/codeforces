#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

#define int long long

int n , m , x , y , A[N] , B[N] , S[N] , sub[N] , it[N];

void add(int l , int r , int tag) {
	it[l] += tag; it[r + 1] -= tag;
}

main(void) {
	scanf("%lld" , &n);
	for(int i = 1;i <= n;++ i) scanf("%lld" , &A[i]);
	for(int i = 1;i <= n;++ i) scanf("%lld" , &B[i]) , S[i] = S[i - 1] + B[i];
	for(int i = 1;i <= n;++ i) {
		if(A[i] + S[i - 1] > S[n]) {
			add(i , n , 1); continue;
		}
		int now = lower_bound(S + 1 , S + n + 1 , A[i] + S[i - 1]) - S;
		add(i , now , 1);
		int K = S[now] - S[i - 1] - A[i];
		sub[now] -= K;
	}
	for(int i = 1;i <= n;++ i) {
		it[i] += it[i - 1];
		printf("%lld " , it[i] * B[i] + sub[i]);
	}
	
}