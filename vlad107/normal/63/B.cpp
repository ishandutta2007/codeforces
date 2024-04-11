#include <stdio.h>
int res,n,m,a[111];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	a[n]=m;
	while (a[0]<m){
		res++;
		for (int i=0;i<n;i++){
			if (a[i]==m)break;
			if (a[i]==a[i+1])continue;
			a[i]++;
		}
	}
	printf("%d\n",res);
}