#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int n,a[N],q[N];
void solve(){
	long long sum=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=2;i<n;i++)
		sum+=(a[i]+1)/2;
	int s=0;
	for (int i=2;i<n;i++)
		if (a[i]!=1) s=1;
	printf("%lld\n",s&&(n!=3||a[2]%2!=1)?sum:-1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}