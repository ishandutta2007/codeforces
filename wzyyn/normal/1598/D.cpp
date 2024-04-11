#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,sx[N],sy[N],a[N],b[N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) sx[i]=sy[i]=0;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		sx[a[i]]++;
		sy[b[i]]++;
	}
	long long ans=1ll*n*(n-1)*(n-2)/6;
	for (int i=1;i<=n;i++)
		ans-=1ll*(sx[a[i]]-1)*(sy[b[i]]-1);
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}