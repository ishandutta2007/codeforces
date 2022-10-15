#include "bits/stdc++.h"
using namespace std;

const int maxn=107;
int n;
int d[8][5];

int main(){
	scanf("%d",&n);
	for (int i=0;i<4;++i){
		for (int j=1;j<=n;++j){
			for (int k=1;k<=n;++k){
				char u;
				cin>>u;
				d[i][0]+=(u-'0'!=(j+k)%2);
			}
		}
	}
	for (int i=0;i<4;++i){
		d[i][1]=n*n-d[i][0];
	}
	int ans=maxn*maxn*5;
	for (int i=0;i<2;++i){
		for (int j=0;j<2;++j){
			for (int k=0;k<2;++k){
				for (int l=0;l<2;++l){
					if (i+j+k+l!=2) continue;
					ans=min(ans,d[0][i]+d[1][j]+d[2][k]+d[3][l]);
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}