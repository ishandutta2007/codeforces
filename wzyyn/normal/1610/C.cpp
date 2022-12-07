#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,a[N],b[N];
bool check(int x){
	int p=0;
	for (int i=1;i<=n;i++)
		if (a[i]>=p&&b[i]>=x-p-1)
			if ((++p)==x) return 1;
	return 0;
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&b[i],&a[i]);
	int l=1,r=n,ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid))
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}