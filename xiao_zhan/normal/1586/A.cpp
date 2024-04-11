#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500];

bool chk(int x){
	int i;
	for(i=2;i*i<=x;i++){
		if(!(x%i))return 1;
	}
	return 0;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		k=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			k+=a[i];
		}
		if(chk(k)){
			printf("%d\n",n);
			for(i=1;i<=n;i++){
				printf("%d ",i);
			}
			puts("");
			continue;
		}
		for(i=1;i<=n;i++){
			if(chk(k-a[i])){
				printf("%d\n",n-1);
				for(j=1;j<=n;j++){
					if(j==i)continue;
					printf("%d ",j);
				}
				puts("");
				goto aaa;
			}
		}
		aaa:;
	}
}