#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	if (n%3!=2) printf("1 1 %d\n",n-2);
	else printf("1 2 %d\n",n-3);
	return 0;
}