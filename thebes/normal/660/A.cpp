#include <bits/stdc++.h>
using namespace std;

int GCD(int x,int y){return(!x)?y:GCD(y%x,x);}
int a[1004], N, i, c;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=N-1;i++){
		if(GCD(a[i],a[i+1])!=1) c++;
	}
	for(printf("%d\n%d ",c,a[1]),i=1;i<=N-1;i++){
		if(GCD(a[i],a[i+1])!=1)
			printf("1 %d ",a[i+1]);
		else printf("%d ",a[i+1]);
	}
	return 0;
}