#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,m,sz,x;
int g[55][10010];
bool solve() {
	for (int i=1;i<=m;i++)
	for (int j=i+1;j<=m;j++) {
		int flag=0;
		for (int k=1;k<=n;k++)
			if (g[i][k]&g[j][k]) { flag=1; break; }
		if (!flag) return 0;
	}
	return 1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(m); read(n);
	for (int i=1;i<=m;i++) {
		read(sz);
		for (int j=1;j<=sz;j++)
			read(x),g[i][x]=1;
	}
	if (!solve()) printf("im");
	printf("possible\n");
	return 0;
}