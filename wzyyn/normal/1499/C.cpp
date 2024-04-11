#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

int n,a[100005];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	long long S=a[1]+a[2],ans=1ll<<60;
	int mn1=a[1],mn2=a[2];
	for (int i=3;i<=n+1;i++){
		int l1=(i/2),l2=(i-1-l1);
		ans=min(ans,S+1ll*mn1*(n-l1)+1ll*mn2*(n-l2));
		if (i&1) mn1=min(mn1,a[i]);
		else mn2=min(mn2,a[i]);
		S+=a[i];
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}