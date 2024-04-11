#include<bits/stdc++.h>
#define N 200005

int T;

int n,k,a[N],s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=2;i<=n;i++)
			s[i]=s[i-1]+(a[i]*2>a[i-1]);
		int res=0;
		for(int i=1;i<=n-k;i++)
			if(s[i+k]-s[i]==k)
				res++;
		printf("%d\n",res);
	}
}