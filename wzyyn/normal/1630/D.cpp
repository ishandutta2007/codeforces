#include<bits/stdc++.h>

using namespace std;

const int N=1000005;
int n,m,x;
int a[N];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&x);
	for (int i=2;i<=m;i++){
		int y;
		scanf("%d",&y);
		x=gcd(x,y);
	}
	if (x==1){
		long long ans=0;
		for (int i=1;i<=n;i++) ans+=abs(a[i]);
		cout<<ans<<endl;
		return;
	}
	long long ans0=0;
	long long ans1=0;
	for (int i=1;i<=x;i++){
		long long f0=0,f1=-(1ll<<60);
		for (int j=i;j<=n;j+=x){
			long long g0=max(f0+a[j],f1-a[j]);
			long long g1=max(f0-a[j],f1+a[j]);
			f0=g0; f1=g1;
		}
		ans0+=f0;
		ans1+=f1;
	}
	cout<<max(ans0,ans1)<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}