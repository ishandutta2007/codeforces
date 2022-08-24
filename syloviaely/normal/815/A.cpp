#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[110][110],n,m;
int N=500,where,ans,x[110],y[110];
void check(int K){
	for (int i=1;i<=m;i++) if (A[1][i]<K) return;
	for (int i=1;i<=m;i++) x[i]=A[1][i]-K;
	for (int i=1;i<=n;i++) if (x[1]>A[i][1]) return;
	for (int i=1;i<=n;i++) y[i]=A[i][1]-x[1];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) if (x[j]+y[i]!=A[i][j]) return;
	int num=0;
	for (int i=1;i<=n;i++) num+=y[i];
	for (int i=1;i<=m;i++) num+=x[i];
	if (num<ans) ans=num,where=K;
}
int main(){
	scanf("%d%d",&n,&m); ans=1e9; where=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%d",&A[i][j]);
	for (int i=0;i<=N;i++) check(i);
	if (ans>1e8){
		printf("-1\n"); return 0;
	}
	int K=where;
	for (int i=1;i<=m;i++) x[i]=A[1][i]-K;
	for (int i=1;i<=n;i++) y[i]=A[i][1]-x[1];
	printf("%d\n",ans);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=x[i];j++) printf("col %d\n",i);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=y[i];j++) printf("row %d\n",i);
	return 0;
}