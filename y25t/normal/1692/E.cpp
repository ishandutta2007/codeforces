#include<bits/stdc++.h>
#define N 200005

int T;

int n,m,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),a[i]+=a[i-1];
		if(a[n]<m){
			puts("-1");
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++) if(a[i]>=m){
			ans=std::max(ans,i-int(std::lower_bound(a,a+n+1,a[i]-m)-a+1)+1);
		}
		printf("%d\n",n-ans);
	}
}