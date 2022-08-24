#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,k1,k2;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		int k3; scanf("%d",&k3); if (k3%2==0) k1++; else k2++;
	}
	int k3=n-k;
	if (k3==0){
		if (k2%2) printf("Stannis\n"); else printf("Daenerys\n");
		return 0;
	}
	if (k2<=k3/2){printf("Daenerys\n"); return 0;}
	if (k1<=(k3+1)/2&&k%2){printf("Stannis\n"); return 0;}
	if (k1<=k3/2&&k%2==0){printf("Daenerys\n"); return 0;}
	if (k3%2==0) printf("Daenerys\n"); else printf("Stannis\n");
}