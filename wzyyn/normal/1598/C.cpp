#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,a[N];
long long b[N];
void solve(){
	long long s=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),s+=a[i];
	for (int i=1;i<=n;i++)
		b[i]=1ll*a[i]*n-s;
	sort(b+1,b+n+1);
	long long ans=0;
	int l=1,r=0;
	for (int i=n;i>=1;i--){
		r=min(r,i-1); l=min(l,i);
		for (;r+1<i&&b[r+1]+b[i]<=0;++r);
		for (;l<i&&b[l]+b[i]<0;++l);
		ans+=r-l+1;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}