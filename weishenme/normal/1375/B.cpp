#include<bits/stdc++.h>
using namespace std;
const int N=305;
int T,n,m,a[N][N];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)scanf("%d",&a[i][j]);
		int flag=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
				int cnt=2;
				if (i>1&&i<n)cnt++;
				if (j>1&&j<m)cnt++;
				if (a[i][j]>cnt)flag=1;
				a[i][j]=cnt;
			}
		if (flag)puts("NO");
		else {
			puts("YES");
			for (int i=1;i<=n;i++){
				for (int j=1;j<=m;j++)printf("%d ",a[i][j]);
				puts("");
			}
		}
	}
}