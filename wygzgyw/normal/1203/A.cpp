#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=410;
int T,n,d[maxn],flag;
bool solve() {
	for (int i=1;i<=n;i++) {
		flag=1;
		for (int j=1;j<=n;j++)
		if (d[i+j-1]!=j) { flag=0; break; }
		if (flag) return 1;
	}
	for (int i=1;i<=n;i++) {
		flag=1;
		for (int j=1;j<=n;j++)
		if (d[i+j-1]!=n-j+1) { flag=0; break; }
		if (flag) return 1;
	}
	return 0;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(d[i]),d[i+n]=d[i];
		if (solve()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}