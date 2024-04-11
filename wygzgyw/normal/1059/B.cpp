#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=1010;
int n,m,vis[maxn][maxn];
char s[maxn][maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);read(m);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (int i=1;i+2<=n;i++)
	for (int j=1;j+2<=m;j++) {
		bool flag=1;
		for (int k=i;k<=i+2;k++)
		for (int l=j;l<=j+2;l++)
			if (s[k][l]=='.') {
				if (k!=i+1||l!=j+1) {
					flag=0; break;
				}
			}
		if (flag) {
			for (int k=i;k<=i+2;k++)
			for (int l=j;l<=j+2;l++)
				if (k!=i+1||l!=j+1)
					vis[k][l]=1;
		}
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		if (s[i][j]=='#'&&!vis[i][j]) {
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}