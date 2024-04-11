#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;scanf("%i",&n);
	if(n&1)printf("NO\n");
	else{
		printf("YES\n");
		vector<int> p(n+1,0);
		for(int i=n;i>=1;i--){
			if(!p[i]){
				int k=1<<(32-__builtin_clz(i));
				int j=k-1-i;p[j]=i;p[i]=j;
			}
		}
		for(int i=1;i<=n;i++)printf("%i%c",p[i],i==n?'\n':' ');
	}
	if(n<6||__builtin_popcount(n)==1)printf("NO\n");
	else{
		printf("YES\n");
		if(n==6)printf("5 3 2 6 1 4\n");
		else{
			printf("5 3 2 6 1 7 4 ");
			for(int i=8;i<=n;i*=2){
				for(int j=i+1;j<min(n+1,i*2);j++)printf("%i ",j);
				printf("%i ",i);
			}
			printf("\n");
		}
	}
	return 0;
}