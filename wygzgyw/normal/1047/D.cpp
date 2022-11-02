#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
ll n,m,ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	if (n>m) swap(n,m);
	if (n==1) ans=6*(m/6)+2*max((m%6)-3,0LL);
	else if (n==2&&(m==2||m==3||m==7)) {
		if (m==2) ans=0;
		if (m==3) ans=4;
		if (m==7) ans=12;
	} else {
		ans=n*m;
		if (ans%2==1) ans--;
	}
	printf("%lld\n",ans);
	return 0;
}