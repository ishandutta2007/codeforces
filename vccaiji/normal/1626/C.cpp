#include<bits/stdc++.h>
using namespace std;
int k[110];
int h[110];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&k[i]);
		for(int i=1;i<=n;i++) scanf("%d",&h[i]);
		int j=n;
		int now=k[n]-h[n]+1;
		long long ans=0;
		for(int i=n-1;i>=1;i--){
			if(k[i]>=now) now=min(now,k[i]-h[i]+1);
			else{
				ans+=1ll*(k[j]-now+1)*(k[j]-now+2)/2;
				j=i;
				now=k[i]-h[i]+1;
			}
		}
		ans+=1ll*(k[j]-now+1)*(k[j]-now+2)/2;
		printf("%lld\n",ans);
	}
	return 0;
}