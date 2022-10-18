#include<bits/stdc++.h>
#define P 998244353
#define N 1000005

int T;

int n,k,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		int res=1;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i<=k||a[i-k]==-1)
				res=1ll*res*i%P;
			else if(a[i-k]){
				if(a[i-k]+k>=i)
					res=0;
			}
			else
				res=1ll*res*(k+1)%P;
			if(i>n-k&&a[i]>0)
				res=0;
		}
		printf("%d\n",res);
	}
}