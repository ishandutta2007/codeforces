// author: xay5421
// created: Sun May 30 22:43:29 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=1005;
int T,n,a[N];
void sol(int k1,int k2){
	printf("2 %d %d\n",k2,k1);
	a[k2]-=a[k1];
	printf("1 %d %d\n",k2,k1);
	a[k1]+=a[k2];
	printf("2 %d %d\n",k2,k1);
	a[k2]-=a[k1];
	printf("2 %d %d\n",k2,k1);
	a[k2]-=a[k1];
	printf("1 %d %d\n",k2,k1);
	a[k1]+=a[k2];
	printf("2 %d %d\n",k2,k1);
	a[k2]-=a[k1];
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n)scanf("%d",&a[i]);
		printf("%d\n",n*3);
		for(int i=1;i<=n;i+=2){
			sol(i+1,i);
		}
	}
	return 0;
}