#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n,a[410][410];
int b[410];
int main() {
	read(n);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) a[i][j]=(i*j)%n;
	for (int i=0;i<n;i++) read(b[i]);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) printf("%d ",(a[i][j]+b[i]-a[i][i]+n)%n); puts("");
	}
	return 0;
}