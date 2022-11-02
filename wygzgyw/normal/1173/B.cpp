#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,m;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); m=n/2+1;
	printf("%d\n",m);
	for (int i=1;i<=m;i++)
		printf("1 %d\n",i);
	for (int i=m+1;i<=n;i++)
		printf("%d %d\n",i-m+1,m);
	return 0;
}