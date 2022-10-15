#include<bits/stdc++.h>
using namespace std;

const int maxn=2007;
int n;
int x[maxn],y[maxn],b[4][4];
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;++i) scanf("%d%d",&x[i],&y[i]);
	while (1){
		for (int i=0;i<2;++i){
			for (int j=0;j<2;++j) b[i][j]=0;
		}
		for (int i=0;i<n;++i){
			b[x[i]&1][y[i]&1]++;
		}
		int k=0;
		for (int i=0;i<2;++i){
			for (int j=0;j<2;++j){
				if (b[i][j]>0) k++;
			}
		}
		if (k>1){
			if (b[0][0]+b[1][1]>0&&b[0][0]+b[1][1]<n){
				printf("%d\n",b[0][0]+b[1][1]);
				for (int i=0;i<n;++i){
					if ((x[i]&1)==(y[i]&1)) printf("%d ",i+1);
				}
				return 0;
			}
			else{
				printf("%d\n",b[1][0]+b[1][1]);
				for (int i=0;i<n;++i){
					if (x[i]&1) printf("%d ",i+1);
				}
				return 0;
			}
		}
		for (int i=0;i<n;++i) x[i]>>=1,y[i]>>=1;
	}
	return 0;
}