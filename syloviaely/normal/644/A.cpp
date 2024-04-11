#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int pd[110][110],n,a,b;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	int k1=n/2,k2=n/2; if (n%2) k1++;
	int k3=a*b/2,k4=a*b/2; if (a*b%2) k3++;
	if (k1>k3||k2>k4){
		printf("-1\n"); return 0;
	}
	k1=1,k2=2;
	for (int i=1;i<=a;i++){
		for (int j=1;j<=b;j++)
			if ((i+j)%2==0){
				if (k1<=n) printf("%d ",k1); else printf("0 "); k1+=2;
			} else{
				if (k2<=n) printf("%d ",k2); else printf("0 "); k2+=2;
			}
		printf("\n");
	}
	return 0;
}