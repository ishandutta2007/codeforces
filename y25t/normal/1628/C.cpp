#include<bits/stdc++.h>
#define N 1005

int T;

int n,a[N][N],b[N][N];

int res;
inline void sol(int x,int y){
	res^=a[x][y];
	if(x>1)
		b[x-1][y]^=1;
	if(x<n)
		b[x+1][y]^=1;
	if(y>1)
		b[x][y-1]^=1;
	if(y<n)
		b[x][y+1]^=1;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&a[i][j]),b[i][j]=0;
		res=0;
		for(int i=2;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(!b[i-1][j])
					sol(i,j);
		printf("%d\n",res);
	}
}