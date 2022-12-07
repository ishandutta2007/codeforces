#include<bits/stdc++.h>

using namespace std;

const int N=105;
int f[N][N][N];
int C[N][N];
int n,m,k,mo; 

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&mo);
	for (int i=1;i<=m;i++) f[0][i][0]=1;
	for (int i=2;i<=m;i++) f[1][i][0]=1;
	int tmp=1;
	for (int i=1;i<=n;i++) f[i][1][1]=tmp=1ll*tmp*i%mo;
	for (int i=0;i<=n;i++) C[i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	for (int i=2;i<=n;i++)
		for (int j=1;j<=i;j++){
			int dl=j-1,dr=i-j;
			if (dl>dr) break;
			for (int d=2;d<=m;d++)
				for (int p=0;p<=min(k,dl);p++)
					if (f[dl][d-1][p])
					for (int q=0;q<=min(k-p,dr);q++){
						int way=(dl==dr?1ll:2ll)*C[dl+dr][dl]*f[dl][d-1][p]%mo*f[dr][d-1][q]%mo;
						f[i][d][p+q]=(f[i][d][p+q]+way)%mo;
					}
		}
	cout<<f[n][m][k]<<endl;
}
/*
f[i][j][k]:
i,jk 
*/