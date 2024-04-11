#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int T;
ll n,m,k;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(m); read(k);
		if (n>k||m>k) printf("-1\n");
		else if ((n+k)%2==1&&(m+k)%2==1)
			printf("%lld\n",k-2);
		else if ((n+k)%2==1||(m+k)%2==1) printf("%lld\n",k-1);
		else printf("%lld\n",k);
	}
	return 0;
}