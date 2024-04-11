#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int T,n,a[N];

bool work(){
	for(int i=1;i<n;i++){
		if(a[i]==0&&a[i+1]==1) return 1;
	}
	return 0;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(a[1]==1){
			printf("%d ",n+1);
			for(int i=1;i<=n;i++) printf("%d ",i);
			puts("");
			continue;
		}	
		if(a[n]==0){
			for(int i=1;i<=n;i++) printf("%d ",i);
			printf("%d\n",n+1);
			continue;
		}
		if(work()){
			int flag=1;
			for(int i=1;i<=n;i++){
				printf("%d ",i);
				if(flag&&i<n&&a[i]==0&&a[i+1]==1){
					flag=0;
					printf("%d ",n+1);
				}
			}
			puts("");
			continue;
		}
		printf("-1\n");
	}
	return 0;
}