#include<bits/stdc++.h>
#define ll long long
#define N 1005

int n,a[N];

ll ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!(i&1))
			a[i]=-a[i];
	}
	for(int i=1;i<n;i++){
		ll s=0,mn=0;
		for(int j=i+1;j<=n;j++){
			if((i&1)&&!(j&1)){
				int x=a[i],y=-a[j];
				ans+=std::min(std::max(0ll,x-(-mn)+1),std::max(0ll,y-(s-mn)+1));
				if(j==i+1)
					ans--;
			}
			s+=a[j];
			mn=std::min(mn,s);
		}
	}
	printf("%lld\n",ans);
}