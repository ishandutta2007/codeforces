#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,l=1,r=1e9,f1,f2;
char b[10],w[10];
int main() {
	read(n);
	printf("1 0\n");
	fflush(stdout);
	scanf("%s",b);
	if (b[0]=='b') f1=1; else f1=0;
	for (int i=1,mid;i<n;i++) {
		mid=(l+r)/2;
		printf("1 %d\n",mid);
		fflush(stdout);
		scanf("%s",w);
		if (w[0]=='b') f2=1; else f2=0;
		if (f1==f2) l=mid+1; else r=mid-1;
	}
	printf("0 %d 2 %d\n",l-1,l);
	fflush(stdout);
	return 0;
}