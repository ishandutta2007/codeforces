#include<bits/stdc++.h>
#define N 100005

int T;

int n,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(n==1){
			puts("0");
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++){
				int cnt=0;
				for(int k=1;k<=n;k++)
					if(k==i||k==j||(a[i]-a[k])*(j-k)==(a[j]-a[k])*(i-k))
						cnt++;
				ans=std::max(ans,cnt);
			}
		printf("%d\n",n-ans);
	}
}