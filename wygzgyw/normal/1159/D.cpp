#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,k,a;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(k); a=(n-k)/2;
	for (int i=1;i<=n;i++)
		if (i%(a+1)==0) printf("1");
		else printf("0");
	printf("\n");
	return 0;
}