#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,a[maxn],tot;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=2;i<=n;i++) {
		if (a[i]) continue;
		a[i]=++tot;
		for (int j=i*2;j<=n;j+=i) a[j]=a[i];
	}
	for (int i=2;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}