#include<bits/stdc++.h>
#define ll long long
#define N 505

int T;

int n,a[N][N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n+n;i++)
			for(int j=1;j<=n+n;j++)
				scanf("%d",&a[i][j]);
		ll ans=0;
		for(int i=n+1;i<=n+n;i++)
			for(int j=n+1;j<=n+n;j++)
				ans+=a[i][j];
		int tmp=1e9;
		for(int i=1,ii=0;ii<2;i+=n-1,ii++)
			for(int j=n+1,jj=0;jj<2;j+=n-1,jj++)
				tmp=std::min(tmp,std::min(a[i][j],a[j][i]));
		ans+=tmp;
		printf("%lld\n",ans);
	}
}