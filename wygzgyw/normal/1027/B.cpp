#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int q;
ll ans,n,x,y,d;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(q);
	d=n/2+(n+1)/2;
	while (q--) {
		read(x); read(y);
		if (n==1) {
			printf("1\n"); continue;
		}
		if ((x+y)%2==0) {
			ans=((x-1)/2)*d;
			if (x%2==0) ans+=(n+1)/2;
			ans+=(y+1)/2;
		} else {
			ans=(n*n+1)/2+((x-1)/2)*d;
			if (x%2==0) ans+=n/2;
			ans+=(y+1)/2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}