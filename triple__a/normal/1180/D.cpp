#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m/2;++i){
		for (int j=1;j<=n;++j){
			printf("%d %d\n%d %d\n",j,i,n+1-j,m+1-i);
		}
	}
	if (m%2==1){
		int i=m/2+1;
		for (int j=1;j<=n/2;++j){
			printf("%d %d\n%d %d\n",j,i,n+1-j,i);
		}
		if (n%2==1){
			printf("%d %d\n",n/2+1,i);
		}
	}
	return 0;
}