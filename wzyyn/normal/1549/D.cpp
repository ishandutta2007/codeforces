#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=200005;
int n,p[N];
ll a[N],q[N];
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if (n==1){
		puts("1");
		return;
	}
	int t=1;
	q[1]=abs(a[1]-a[2]);
	p[1]=1;
	int ans=(q[1]==1?1:2);
	for (int i=3;i<=n;i++){
		ll v=abs(a[i]-a[i-1]);
		q[++t]=v; p[t]=i-1;
		for (int j=t-1;j>=1;--j)
			q[j]=gcd(q[j],q[j+1]);
		int nt=1;
		for (int j=2;j<=t;j++)
			if (q[j]!=q[j-1]){
				q[++nt]=q[j];
				p[nt]=p[j];
			}
		t=nt;
		for (int j=1;j<=t;j++)
			if (q[j]!=1) ans=max(ans,i-p[j]+1);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}