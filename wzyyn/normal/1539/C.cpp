#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
long long k,x;
long long a[200005],q[200005];
int main(){
	scanf("%d%lld%lld",&n,&k,&x);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int ans=n;
	for (int i=2;i<=n;i++)
		if (a[i]-a[i-1]<=x) q[i]=0;
		else q[i]=(a[i]-a[i-1]-1)/x;
	sort(q+2,q+n+1);
	for (int i=2;i<=n;i++)
		if (k>=q[i]) k-=q[i],ans--;
	cout<<ans<<endl;
}