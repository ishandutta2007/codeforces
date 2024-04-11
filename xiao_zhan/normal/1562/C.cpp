#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,sb,a[20050],res,len;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%1d",&a[i]);
		}
		len=n/2;
		for(i=len+1;i<=n;i++){
			if(a[i]==0){
				printf("1 %d 1 %d\n",i,i-1);goto aaa;
			}
			if(a[n-i+1]==0){
				printf("%d %d %d %d\n",n-i+2,n,n-i+1,n);goto aaa;
			}
		}
		printf("%d %d %d %d\n",1,n-1,2,n);
		aaa:;
	}
}