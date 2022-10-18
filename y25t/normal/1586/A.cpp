#include<bits/stdc++.h>
#define N 105

int T;

int n,a[N];

inline bool chk(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 1;
	return 0;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int s=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),s+=a[i];
		if(chk(s)){
			printf("%d\n",n);
			for(int i=1;i<=n;i++)
				printf("%d ",i);
			puts("");
		}
		else
			for(int i=1;i<=n;i++)
				if(chk(s-a[i])){
					printf("%d\n",n-1);
					for(int j=1;j<=n;j++)
						if(j!=i)
							printf("%d ",j);
					puts("");
					break;
				}
	}
}