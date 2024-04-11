#include <bits/stdc++.h>
using namespace std;

int mat[51][51], n, i, j, x, p[51];

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			scanf("%d",&mat[i][j]);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			int cnt=0;
			for(int k=1;k<=n;k++)
				if(mat[j][k]==i) cnt++;
			if(n-cnt==i&&p[j]==0)
			{p[j]=i; break;}
		}
	}
	for(i=1;i<=n;i++)
		printf("%d ",p[i]);
	return 0;
}