#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int a,b,c;
int main() {
	//freopen("1.txt","r",stdin);
	read(a); read(b); read(c);
	printf("%d\n",min(a,min(b-1,c-2))*3+3);
	return 0;
}