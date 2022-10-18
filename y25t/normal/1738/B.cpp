#include<bits/stdc++.h>
#define N 100005

int T;

int n,k,s[N],a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=n-k+1;i<=n;i++)
			scanf("%d",&s[i]);
		a[n-k+1]=s[n-k+1]/(n-k+1);
		while(1ll*(n-k+1)*a[n-k+1]<s[n-k+1])
			a[n-k+1]++;
		for(int i=n-k+2;i<=n;i++)
			a[i]=s[i]-s[i-1];
		bool flg=1;
		for(int i=n-k+2;i<=n;i++)
			if(a[i]<a[i-1])
				flg=0;
		puts(flg?"Yes":"No");
	}
}