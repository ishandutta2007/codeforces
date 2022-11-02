#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,a[2010],s;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=2*n;i++) read(a[i]);
	sort(a+1,a+2*n+1);
	for (int i=1;i<=n;i++) s+=a[i];
	for (int i=n+1;i<=2*n;i++) s-=a[i];
	if (s==0) printf("-1\n");
	else {
		for (int i=1;i<=2*n;i++) printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}