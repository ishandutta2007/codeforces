#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=(15e6);
ll a,b,c,ans=1e18;
ll x[maxn],y[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%lld %lld",&a,&b);
	c=a+b;
	x[1]=a;
	for (int i=2;(ll)i*i<=c;i++) {
		x[i]=x[i-1];
		if (a%i==0) x[i]=min(x[i],a/i);
	}
	y[1]=b;
	for (int i=2;(ll)i*i<=c;i++) {
		y[i]=y[i-1];
		if (b%i==0) y[i]=min(y[i],b/i);
	}
	for (ll i=1;i*i<=c;i++)
		if (c%i==0&&(x[i]<=c/i||y[i]<=c/i))
			ans=min(ans,2LL*(i+c/i));
	printf("%lld\n",ans);
	return 0;
}