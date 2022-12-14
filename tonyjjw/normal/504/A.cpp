//*

#include<stdio.h>
#include<algorithm>
#include<queue>
#pragma warning(disable:4996)
#define MN 65536

using namespace std;

int N,S;
int deg[MN], val[MN];
int A[MN], B[MN], ans;

queue<int> Q;

int main()
{
//	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d%d", &deg[i], &val[i]);
	}
	for (i = 0; i < N; i++)if (deg[i] == 1)Q.push(i);
	while (Q.size()){
		int n = Q.front();
		Q.pop();
		if (deg[n] == 0)continue;
		int v = val[n];
		val[n] ^= v;
		val[v] ^= n;

		A[ans] = n,B[ans] = v;
		ans++;
		deg[n]--;
		deg[v]--;
		if (deg[v] == 1)Q.push(v);
	}
	printf("%d\n", ans);
	for (i = 0; i < ans; i++){
		printf("%d %d\n", A[i], B[i]);
	}
	return 0;
}

//*/