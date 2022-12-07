#include<bits/stdc++.h>
using namespace std;

bitset<10005> f[105][105];
void solve(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	puts(f[n][m][k]?"YES":"NO");
}
int main(){
	f[1][1][0]=1;
	for (int i=1;i<=100;i++)
		for (int j=1;j<=100;j++){
			f[i+1][j]|=f[i][j]<<j;
			f[i][j+1]|=f[i][j]<<i;
		}
	int T;
	scanf("%d",&T);
	while (T--) solve();
}