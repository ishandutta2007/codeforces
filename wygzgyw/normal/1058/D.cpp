#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
ll n,m,k,t;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); read(k);
	ll x1,y1,x2,y2,x3,y3;
	x1=y1=0;
	t=2*m*n;
	if (t%k!=0) {
		printf("NO\n");
		return 0;
	}
	t/=k;
	if (t>m*n) {
		printf("NO\n");
		return 0;
	}
	x2=1; y2=m;
	x3=t/m;
	if (t%m!=0) x3++;
	y3=x3*y2-t;
	printf("YES\n");
	printf("%lld %lld\n",x1,y1);
	printf("%lld %lld\n",x2,y2);
	printf("%lld %lld\n",x3,y3);
	return 0;
}