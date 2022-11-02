#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
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
	int mx=a-b+c;
	int mn=a-b-c;
	if (mn>0) printf("+\n");
	else if (mx<0) printf("-\n");
	else if (mn==0&&mx==0) printf("0\n");
	else printf("?\n");
	return 0;
}