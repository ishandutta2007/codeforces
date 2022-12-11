#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int a[3][1005];
		for(int i=1;i<=2;i++){
			for(int o=1;o<=n;o++){
				scanf("%1d",&a[i][o]); 
			}
		}
		if(a[2][n]){
			puts("NO");
			continue;
		}
		int pd=0;
		for(int i=1;i<=n;i++){
			if(a[1][i]&&a[2][i]){
				puts("NO");
				pd=1;
				break;
			}
		}
		if(!pd)puts("YES");
	}
	return 0;
}