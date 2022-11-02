#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=1010;
int n,m,d[maxn],tot,e[maxn],ans[maxn],u[maxn],mx[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); m=n;
	for (int i=1;i<n;i++) {
		int x,y; read(x); read(y);
		if (x==n&&y==n) {
			printf("NO\n");
			break;
		}
		if (x==n) d[i]=y;
		else if (y==n) d[i]=x;
		else {
			printf("NO\n");
			return 0;
		}
		m=min(m,d[i]);
	}
	sort(d+1,d+n);
	for (int i=1;i<n;i++)
		u[d[i]]=1;
	for (int i=1;i<=n;i++)
		if (!u[i]) e[++tot]=i;
	ans[n]=n;
	int pos=0;
	for (int i=1;i<n;i++) {
		if (d[i]!=d[i-1]) ans[i]=d[i];
		else ans[i]=e[++pos];
	}
	if (pos>tot) printf("NO\n");
	else {
		for (int i=1;i<n;i++)
			mx[i]=max(mx[i-1],ans[i]);
		for (int i=1;i<n;i++)
			if (mx[i]!=d[i]) {
				printf("NO\n");
				return 0;
			}
		printf("YES\n");
		for (int i=1;i<n;i++)
			printf("%d %d\n",ans[i],ans[i+1]);
	}
	return 0;
}