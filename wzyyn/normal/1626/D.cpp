#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,a[N],q[N],tb[N]; 
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	tb[0]=1;
	for (int d=1;d/2+1<=n;d<<=1)
		for (int i=d/2+1;i<=d&&i<=n;i++)
			tb[i]=d;
	sort(a+1,a+n+1);
	int t=0;
	for (int i=1;i<=n;i++)
		if (a[i]!=a[i+1]||i==n) q[++t]=i;
	int ans=1<<30;
	for (int d=1;;d<<=1){
		int p=q[upper_bound(q+1,q+t+1,d)-q-1];
		for (int D=1;;D<<=1){
			int pp=q[upper_bound(q+1,q+t+1,p+D)-q-1];
			ans=min(ans,d+D+tb[n-pp]);
			if (p+D>=n) break;
		}
		if (p>=n) break;
	}
	printf("%d\n",ans-n);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}