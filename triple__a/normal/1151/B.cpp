#include<bits/stdc++.h>
using namespace std;

int n,m,mat[507][507];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			scanf("%d",&mat[i][j]);
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<m;++j){
			if (mat[i][j]!=mat[i][j+1]){
				printf("TAK\n");
				int u=0;
				for (int k=1;k<=n;++k){
					u^=mat[k][1];
				}
				if (u^mat[i][1]^mat[i][j]){
					for (int k=1;k<=n;++k){
						if (k==i) {printf("%d ",j); continue;}
						printf("%d ",1);
					}
				}
				else{
					for (int k=1;k<=n;++k){
						if (k==i) {printf("%d ",j+1); continue;}
						printf("%d ",1);
					}
				}
				return 0;
			}
		}
	}
	int u=0;
	for (int i=1;i<=n;++i){
		u^=mat[i][1];
	}
	if (u){
		printf("TAK\n");
		for (int i=1;i<=n;++i){
			printf("%d\n",1);
		}
		return 0;
	}
	printf("NIE");
	return 0;
}