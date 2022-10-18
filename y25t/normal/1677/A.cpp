#include<bits/stdc++.h>
#define N 5005

int T;

int n,a[N];

int c[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			c[i]=0;
		long long res=0;
		for(int i=1;i<=n;i++){
			for(int j=n,t=0;j>i;j--){
				res+=1ll*t*c[a[j]];
				if(a[j]<a[i])
					t++;
			}
			for(int j=a[i];j<=n;j++)
				c[j]++;
		}
		printf("%lld\n",res);
	}
}