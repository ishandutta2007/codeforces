#include<bits/stdc++.h>
using namespace std;
int T,n,a[100100],mx,mn;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),mx=mn=1;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>a[mx])mx=i;
			if(a[i]<a[mn])mn=i;
		}
		printf("%d %d\n",mx,mn);
	}
	return 0;
}