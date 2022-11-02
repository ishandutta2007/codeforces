#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,d,m,x,y;
int a[110][110];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(d);
	for (int i=0;i<d;i++)
	for (int j=0;j<d-i;j++)
		a[i][j]=1;
	for (int i=d+1;i<=n;i++)
	for (int j=0;j<=i-d-1;j++)
		a[i][j]=1;
	for (int i=0;i<=n-d-1;i++)
	for (int j=i+d+1;j<=n;j++)
		a[i][j]=1;//,printf("%d %d\n",i,j);
	for (int i=n-d+1;i<=n;i++)
	for (int j=n+(n-d+1)-i;j<=n;j++)
		a[i][j]=1;//,printf("%d %d\n",i,j);
	read(m);
	/*for (int i=0;i<=n;i++) {
	for (int j=0;j<=n;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}*/
	for (int i=1;i<=m;i++) {
		read(x); read(y);
		if (a[x][y]) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}