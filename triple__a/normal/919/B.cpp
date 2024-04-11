#include<iostream>
#include<cstdio>

bool isp(int n){
	int ans=0;
	while(n){
		ans+=n%10;
		n/=10;
	}
	if (ans==10) return 1;
	return 0;
} 

int main(){
	int n,k=0;
	scanf("%d",&n);
	int i;
	for (i=1;k<n;++i){
		if (isp(i)){
			++k;
		}
	}
	printf("%d\n",i-1);
	return 0;
}