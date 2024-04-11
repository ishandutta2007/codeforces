#include <bits/stdc++.h>
using namespace std;
const int maxn=(1e6);
typedef long long ll;
int n;
ll a[maxn],b[maxn],ans,t,tmp;
ll s[maxn],s1[maxn],s2[maxn];
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
	for (int i=n;i>=1;i--) s[i]=s[i+1]+a[i]+b[i];
	s1[n]=b[n]; s2[n]=a[n];
	for (int i=n-1;i>=1;i--) {
		s1[i]=s1[i+1]+s[i+1]+b[i]*((n-i+1)*2-1);
		s2[i]=s2[i+1]+s[i+1]+a[i]*((n-i+1)*2-1);
	}
	int x=0,y=1;
	for (int i=1;i<=2*n;i++) {
		if (i%2==1) {
			if (!x) ans=max(ans,tmp+t*s[y]+s1[y]);
			else ans=max(ans,tmp+t*s[y]+s2[y]);
		}
		if (!x) tmp+=t*a[y]; else tmp+=t*b[y]; t++;
		if (i%2==1) x^=1;
		else y++;
	}
	printf("%lld\n",ans);
	return 0;
}