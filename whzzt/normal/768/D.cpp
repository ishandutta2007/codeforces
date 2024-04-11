#include "bits/stdc++.h"
using namespace std;

const int N = 1005;
int n,q,p;
double g[N][N*20];

int main(){
	cin>>n>>q;g[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=i;j<=20000;j++)g[i][j]=(i*1.0/n)*(g[i][j-1]+g[i-1][j-1]);
	for(int i=1;i<=q;i++){
		scanf("%d",&p);int k;
		for(k=20000;g[n][k]>p*0.0005;k--);
		printf("%d\n",k+1);
	}
	return 0;
}