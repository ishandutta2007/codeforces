#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[105],l,r,res;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		res=1145141919ll;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				for(k=i;k<=j;k++){
					a[k]=a[i+j-k]=(a[k]&a[i+j-k]);
				}
			}
		}
		for(i=1;i<=n;i++){
			res=min(res,a[i]);
		}
		printf("%lld\n",res);
	}
}