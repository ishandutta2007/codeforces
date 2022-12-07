#include<bits/stdc++.h>

using namespace std;

const int N=405;
int n,m,a[N][N];
int f[N][N],re;
char s[N][N];
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for (int j=1;j<=m;j++)
			a[j][i]=a[j][i-1]+s[i][j]-'0';
	}
	swap(n,m);
	int re=1<<30;
	for (int j=1;j<=m;j++)
		for (int k=j;k<=m;k++)
			f[j][k]=1<<30;
	for (int i=3;i<n;i++)
		for (int j=1;j<=m;j++)
			for (int k=j+4;k<=m;k++){
				int v1=(s[j][i]=='0')+(s[k][i]=='0')+(a[i][k-1]-a[i][j]);
				int v2=(s[j][i-1]=='0')+(s[k][i-1]=='0')+(a[i-1][k-1]-a[i-1][j]);
				v2=v2+v1+(k-j-1)-(a[i-2][k-1]-a[i-2][j]);
				f[j][k]=min(f[j][k]+v1,v2);
				re=min(re,f[j][k]+((k-j-1)-(a[i+1][k-1]-a[i+1][j])));
			}
	cout<<re<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}