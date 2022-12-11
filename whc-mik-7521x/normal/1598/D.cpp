#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,a[200005],b[200005];
		map<int,int>ca;
		map<int,int>cb;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i],&b[i]);
			ca[a[i]]++;
			cb[b[i]]++;
		}
		long long ans=1ll*n*(n-1)*(n-2)/3/2;
		for(int i=1;i<=n;i++){
			ans-=1ll*(ca[a[i]]-1)*(cb[b[i]]-1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}