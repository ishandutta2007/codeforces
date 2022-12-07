#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;
int n,m,a[25][25];
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			a[i][j]=0;
	for (int i=1;i<=n;i++)
		if (i%2==1) a[i][1]=1;
	for (int i=3;i<=n;i++)
		if (i%2==1) a[i][m]=1;
	for (int i=1;i<=m;i++)
		if (i%2==1) a[1][i]=1;
	for (int i=3;i<=m-2;i++)
		if (i%2==1) a[n][i]=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			printf("%d",a[i][j]);
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}