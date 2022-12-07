#include<bits/stdc++.h>
using namespace std;

int a[105][105];
int n,m,l[105];
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
		sort(a[i]+1,a[i]+m+1);
	}
	for (int i=1;i<=n;i++) l[i]=0;
	for (int i=1;i<=m;i++){
		int p=1;
		for (int j=1;j<=n;j++)
			if (a[j][l[j]+1]<a[p][l[p]+1])
				p=j;
		++l[p];
	}
	int s=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			printf("%d ",a[i][(j+m-s-1)%m+1]);
		s+=l[i];
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}