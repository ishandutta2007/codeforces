#include<bits/stdc++.h>
#define N 1005

int T;

int n,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		std::sort(a+1,a+n+1);
		printf("%d\n",a[n]+a[n-1]);
	}
}