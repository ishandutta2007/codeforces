#include<bits/stdc++.h>
using namespace std;
int a[210000];
int vis[210000];
int o[30];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=0;i<30;i++) o[i]=0;
		for(int i=0;i<30;i++)for(int j=1;j<=n;j++) if((a[j]>>i)&1) o[i]++;
		int pp=0;
		for(int i=0;i<30;i++) pp=__gcd(pp,o[i]);
		for(int i=1;i<=n;i++)if(pp%i==0) printf("%d ",i);
		printf("\n");
	}
	return 0;
}