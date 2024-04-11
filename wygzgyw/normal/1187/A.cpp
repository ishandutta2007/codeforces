#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,s,t;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(s); read(t);
		printf("%d\n",max(n-s+1,n-t+1));
	}
	return 0;
}