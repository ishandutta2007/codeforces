#include<bits/stdc++.h>
using namespace std;
const int N = 500009;
int T,n,a[N];
 
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n<=2) printf("-1\n");
		else if(a[1]+a[2]<=a[n]) printf("1 2 %d\n",n);
		else printf("-1\n");
	}
	return 0;
}