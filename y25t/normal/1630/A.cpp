#include<bits/stdc++.h>

int T;

int n,k;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		if(k==n-1){
			if(n==4){
				puts("-1");
				continue;
			}
			printf("%d %d\n%d %d\n%d %d\n",n-1,n-2,1,3,0,(n-1)^3);
			for(int i=2;i<n-1;i++){
				int j=(n-1)^i;
				if(i==3||i==n-2)
					continue;
				if(i<j)
					printf("%d %d\n",i,j);
			}
			continue;
		}
		std::vector<int> cnt(n);
		int res=0,c=0;
		for(int i=1;i<n-1;i++){
			int j=(n-1)^i;
			if(i==k){
				cnt[i]++,cnt[n-1]++,cnt[0]++,cnt[j]++;
				printf("%d %d\n",i,n-1);
				printf("%d %d\n",0,j);
				res+=(i&(n-1))+(0&j),c+=2;
			}
			else if(i<j&&j!=k)
				printf("%d %d\n",i,j),res+=i&j,c++,cnt[i]++,cnt[j]++;
		}
		if(!k)
			printf("%d %d\n",0,n-1),res+=0&(n-1),c++,cnt[0]++,cnt[n-1]++;
		assert(res==k&&c==n/2);
		for(int i=0;i<n;i++)
			assert(cnt[i]==1);
	}
}