#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n%4>1)return printf("NO\n"),0;
	printf("YES\n");
	for(int i=1;i<n;i+=4){
		if(n%4)printf("%d %d\n%d %d\n%d %d\n",i+2,n,i+2,i+3,i+3,n);
		else printf("%d %d\n",i+2,i+3);
		printf("%d %d\n",i,i+2);
		printf("%d %d\n",i+1,i+3);
		printf("%d %d\n",i+1,i+2);
		printf("%d %d\n",i,i+3);
		if(n%4)printf("%d %d\n%d %d\n%d %d\n",i,n,i,i+1,i+1,n);
		else printf("%d %d\n",i,i+1);
	}
	for(int i=1;i<n;i+=4)
		for(int j=i+4;j<n;j+=4){
			printf("%d %d\n",i+3,j+2);
			printf("%d %d\n",i+2,j+2);
			printf("%d %d\n",i+3,j+1);
			printf("%d %d\n",i,j+1);
			printf("%d %d\n",i+1,j+3);
			printf("%d %d\n",i+2,j+3);
			printf("%d %d\n",i+1,j+2);
			printf("%d %d\n",i+1,j+1);
			printf("%d %d\n",i+3,j);
			printf("%d %d\n",i+3,j+3);
			printf("%d %d\n",i,j+2);
			printf("%d %d\n",i,j+3);
			printf("%d %d\n",i+2,j);
			printf("%d %d\n",i+2,j+1);
			printf("%d %d\n",i+1,j);
			printf("%d %d\n",i,j);
		}
	//what fuking shit it is!!!
}