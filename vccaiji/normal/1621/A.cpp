#include<bits/stdc++.h> 
using namespace std;
int main(){
	int t,n,k;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&k);
		if(2*k<=n+1){
			for(int j=1;j<=n;j++){
				for(int kk=1;kk<=n;kk++){
					if((j==kk)&&(j%2==1)&&(j<=2*k-1)) printf("R");
					else printf(".");
				}
				printf("\n");
			}
		}
		else printf("-1\n");
	}
	return 0;
}