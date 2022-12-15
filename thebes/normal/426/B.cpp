#include <bits/stdc++.h>
using namespace std;

int mat[101][101], n, m, i, j;
int wts(int w){
	if(w%2) return w;
	bool flag = false;
	for(i=1;i<=w/2;i++){
		for(j=1;j<=m;j++)
			if(mat[i][j]!=mat[w-i+1][j]) flag=1;
	}
	return (flag)?w:wts(w/2);
}

int main(){
	for(scanf("%d%d",&n,&m),i=1;i<=n;i++){
		for(j=1;j<=m;j++) getchar(),mat[i][j]=getchar()-'0';
	}
	printf("%d\n",wts(n));
	return 0;
}