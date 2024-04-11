#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,a[100010];

int main() {
	read(T); while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		int F=0;
		for (int i=1;i<=n;i++) {
			int flag=1;
			for (int j=i+1;j>1;j--) if (a[i]%j!=0) { flag=0; break; }
			if (flag) { F=1; break; }
		}
		if (F) puts("NO"); else puts("YES");
	}
	return 0;
}