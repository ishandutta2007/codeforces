#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int get(int k1){
	int ans=0;
	for (int i=2;i*i<=k1;i++){
		if (k1%i==0)return 2;
	}
	return 1;
}
int n;
int main(){
	scanf("%d",&n);
	if (n<=2) printf("1\n"); else printf("2\n");
	for (int i=2;i<=n+1;i++) printf("%d ",get(i));
	printf("\n");
}