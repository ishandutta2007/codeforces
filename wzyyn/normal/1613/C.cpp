#include<bits/stdc++.h>

using namespace std;

int n,a[105];
long long h;

bool check(long long v){
	long long s=v;
	for (int i=1;i<n;i++)
		s+=min(1ll*a[i+1]-a[i],v);
	return s>=h;
}
void solve(){
	scanf("%d%lld",&n,&h);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	long long l=1,r=h,ans;
	while (l<=r){
		long long mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}