#include<bits/stdc++.h>

using namespace std;

int n,k,a[15],p[15];
void solve(){
	p[0]=1;
	scanf("%d%d",&n,&k);
	++k;
	for (int i=1;i<=9;i++) p[i]=p[i-1]*10;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	long long re=0;
	for (int i=1;i<n;i++)
		if (p[a[i+1]-a[i]]-1>=k){
			re+=1ll*k*p[a[i]];
			k=0; break;
		}
		else{
			re+=1ll*(p[a[i+1]-a[i]]-1)*p[a[i]];
			k-=p[a[i+1]-a[i]]-1;
		}
	re=re+1ll*p[a[n]]*k;
	printf("%lld\n",re);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}