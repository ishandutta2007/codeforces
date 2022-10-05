#include<bits/stdc++.h>
using namespace std;
char a[210000];
int main(){
	int n,q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) printf("%lld ",(((long long)j)<<(i+j-2)));
		printf("\n");
		fflush(stdout);
	}
	scanf("%d",&q);
	while(q--){
		long long ans;
		scanf("%lld",&ans);
		ans-=1;
		int nowj=1;
		printf("1 1\n");
		fflush(stdout);
		for(int i=1;i<=2*n-2;i++){
			long long u=((ans>>i)&1ll);
			if(u!=(nowj&1)) nowj++;
			ans-=(((long long)nowj)<<i);
			printf("%d %d\n",i+2-nowj,nowj);
			fflush(stdout);
		}
	}
	return 0;
}