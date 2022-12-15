#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+6;
int Q, ps[N][10], g[N], i, x, y, w;
int f(int n){
	int ret=1;
	while(n){
		if(n%10) ret*=(n%10);
		n /= 10;
	}
	return ret;
}

int main(){
	for(i=1;i<N;i++){
		if(i<10) g[i]=i;
		else g[i]=g[f(i)];
		for(int j=1;j<=9;j++)
			ps[i][j]=ps[i-1][j];
		ps[i][g[i]]++;
	}
	for(scanf("%d",&Q);Q>0;Q--){
		scanf("%d%d%d",&x,&y,&w);
		printf("%d\n",ps[y][w]-ps[x-1][w]);
	}
	return 0;
}