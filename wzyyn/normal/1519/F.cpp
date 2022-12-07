#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[10],b[10];
int C[10][10],P[10];
int f[5][50000],g[5][50000];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&C[i][j]);
	P[1]=1;
	for (int i=2;i<=m+1;i++)
		P[i]=5*P[i-1];
	int IS=0;
	for (int i=1;i<=m;i++)
		IS=IS+b[i]*P[i];
	memset(f,30,sizeof(f));
	f[a[1]][IS]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			memcpy(g,f,sizeof(f));
			for (int k=0;k<=a[i];k++)
				for (int l=0;l<P[m+1];l++){
					if (f[k][l]>=1e8) continue;
					int re=l/P[j]%5;
					for (int m=1;m<=k&&m<=re;m++)
						g[k-m][l-m*P[j]]=min(g[k-m][l-m*P[j]],f[k][l]+C[i][j]);
				}
			memcpy(f,g,sizeof(f));
			if (j==m){
				for (int k=1;k<=a[i];k++)
					for (int l=0;l<P[m+1];l++)
						f[k][l]=1<<30;
				for (int l=0;l<P[m+1];l++)
					swap(f[0][l],f[a[i+1]][l]);
			}
		}
	int ans=1<<30;
	for (int l=0;l<P[m+1];l++)
		ans=min(ans,f[0][l]);
	if (ans>1e8) ans=-1;
	cout<<ans<<endl;
}
/*
f[i][j][k]:ij 
*/