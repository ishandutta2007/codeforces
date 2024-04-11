#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(5e5)+10;
int n,m,sz[maxn];
int fa[maxn];
int find(int x) {
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); int k,x,y,X,Y;
	for (int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for (int i=1;i<=m;i++) {
		read(k);
		if (!k) continue;
		read(x); k--;
		while (k--) {
			read(y);
			X=find(x); Y=find(y);
			if (X==Y) continue;
			if (sz[X]>sz[Y]) swap(X,Y);
			fa[X]=Y; sz[Y]+=sz[X];
		}
	}
	for (int i=1;i<=n;i++)
		printf("%d ",sz[find(i)]);
	printf("\n");
	return 0;
}