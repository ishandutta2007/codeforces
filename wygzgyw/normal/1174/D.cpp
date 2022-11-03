#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,x,tot;
int a[1<<18];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(x); tot=-1;
	for (int i=0;i<(1<<n);i++) {
		if ((x^i)>=i) a[++tot]=i;
	}
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) printf("%d ",a[i]^a[i-1]);
	printf("\n");
	return 0;
}