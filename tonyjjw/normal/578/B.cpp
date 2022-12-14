//*

#include<stdio.h>
#include<vector>
#include<algorithm>
#define MN 200000

using namespace std;

typedef long long ll;

int N, K, X;
ll A[MN];
ll pre[MN];
ll suf[MN];

int main(){
//	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &N, &K, &X);
	ll v = 1;
	for (int i = 0; i < K; i++)v *= X;
	for (int i = 0; i < N; i++){
		scanf("%lld", &A[i]);
	}
	pre[0] = A[0];
	for (int i = 1; i < N; i++){
		pre[i] = pre[i - 1] | A[i];
	}
	suf[N - 1] = A[N - 1];
	for (int i = N - 2; i >= 0; i--){
		suf[i] = suf[i + 1] | A[i];
	}
	ll ans = 0;
	for (int i = 0; i < N; i++){
		ll v1,v2;
		if (i == 0)v1 = 0;
		else v1 = pre[i - 1];
		if (i == N - 1)v2 = 0;
		else v2 = suf[i + 1];
		if (ans < (v1 | v2 | (A[i] * v))){
			ans = (v1 | v2 | (A[i] * v));
		}
	}
	printf("%lld\n", ans);
	return 0;
}

//*/