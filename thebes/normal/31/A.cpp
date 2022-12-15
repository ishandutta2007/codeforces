#include <bits/stdc++.h>
using namespace std;

int wtf, i, j, k, arr[101], n;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				if(arr[i]==arr[j]+arr[k]&&i!=j&&j!=k&&i!=k){
					printf("%d %d %d\n",i,j,k);
					return 0;
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}