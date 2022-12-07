#include<bits/stdc++.h>

using namespace std;

const int mo=998244353;
const int N=505;

int p[N][N],C[N][N];
int f[N][N],n,m;
void init(){
	for (int i=0;i<N;i++)
		C[i][0]=p[i][0]=1;
	for (int i=0;i<N;i++)
		for (int j=1;j<N;j++)
			p[i][j]=1ll*p[i][j-1]*i%mo;
	for (int i=1;i<N;i++)
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	for (int v=1;v<=m;v++)
		for (int i=2;i<=n;i++){
			f[v][i]=p[min(v,i-1)][i];
			if (i-1<v){
				int nv=v-(i-1);
				for (int j=1;j<=i;j++)
					f[v][i]=(f[v][i]+1ll*C[i][j]*f[nv][j]%mo*p[i-1][i-j])%mo;
			}
		}
	cout<<f[m][n]<<endl;
}
/*
f[i][j]:
 i 
 j 

*/