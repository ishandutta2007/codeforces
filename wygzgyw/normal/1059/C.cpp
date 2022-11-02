#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e6)+5;
typedef long long ll;
void dfs(int n,int s) {
	if (n==0) return;
	if (n/2>n/3) {
		for (int i=1;i<=n-n/2;i++)
			printf("%d ",s);
		dfs(n/2,s*2);
	} else {
		for (int i=1;i<=n-n/3;i++)
			printf("%d ",s);
		dfs(n/3,s*3);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	int n; read(n);
	dfs(n,1);
	printf("\n");
	return 0;
}