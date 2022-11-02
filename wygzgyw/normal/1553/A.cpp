#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n;

int main() {
	read(T); while (T--) {
		read(n);
		if (n<9) { puts("0"); continue; }
		n-=9; printf("%d\n",n/10+1);
	}
	return 0;
}