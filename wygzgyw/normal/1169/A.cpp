#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,a,b,c,d;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(a); read(c); read(b); read(d);
	while (1) {
		if (a==b) { printf("Yes\n"); return 0; }
		a++; if (a>n) a=1;
		b--; if (b<1) b=n;
		if (a==c||b==d) break;
	}
	if (a==b) printf("Yes\n");
	else printf("No\n");
	return 0;
}