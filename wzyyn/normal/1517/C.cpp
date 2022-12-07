#include<bits/stdc++.h>
using namespace std;

const int N=505;
int n,p[N],a[N][N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for (int i=1;i<=n;i++)
		a[i][i]=p[i];
	for (int i=2;i<=n;i++){
		int nx=i,ny=1;
		for (int x=i-1,y=1;x<=n;x++,y++)
			if (a[x][y]>=i){
				a[nx][ny]=a[x][y];
				++nx; ++ny;
			}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++)
			printf("%d ",a[i][j]);
		puts("");
	}
}