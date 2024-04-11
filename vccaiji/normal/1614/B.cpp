#include<bits/stdc++.h>
using namespace std;
int _;
int a[1100000];
pair<int,int> h[1100000];
int o[1100000];
int main(){
	scanf("%d",&_);
	while(_--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)h[i]=make_pair(a[i],i);
		sort(h+1,h+n+1);
		long long ans=0;
		if(n&1){
			o[0]=0;
			ans+=2ll*h[1].first*((n+1)/2);
			o[h[1].second]=(n+1)/2;
			for(int i=2;i<=n;i+=2){
				ans+=2ll*h[i].first*((n+1)/2-i/2);
				o[h[i].second]=(n+1)/2-i/2;
				ans+=2ll*h[i+1].first*((n+1)/2-i/2);
				o[h[i+1].second]=-((n+1)/2-i/2);
			}
		}
		else{
			o[0]=0;
			for(int i=1;i<=n;i+=2){
				ans+=2ll*h[i].first*(n/2-(i-1)/2);
				o[h[i].second]=n/2-(i-1)/2;
				ans+=2ll*h[i+1].first*(n/2-(i-1)/2);
				o[h[i+1].second]=-(n/2-(i-1)/2);
			}
		}
		cout<<ans<<endl;
		for(int i=0;i<=n;i++)printf("%d ",o[i]);
		printf("\n");
	}
	return 0;
}