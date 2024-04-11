#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,m;
int main() {
	//freopen("1.txt","r",stdin);
    for (int i=1;i<=2230;i++) printf("5");
    printf("\n");
    for (int i=1;i<=2229;i++) printf("4");
    printf("5\n");
	return 0;
}