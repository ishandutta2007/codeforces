#include<bits/stdc++.h>
using namespace std;
int p=1000000007;
int r,g;
int a[300000]={};
int main(){
	scanf("%d%d",&r,&g);
	int h=1;
	for(;;){
		if(h*(h+1)/2>r+g) break;
		h++;
	}
	h--;
	if(r>g){
		int u=r;
		r=g;
		g=u;
	}
	a[0]=1;
	for(int i=1;i<=h;i++){
		for(int j=r;j>=i;j--) a[j]=(a[j]+a[j-i])%p;
	}
	int sum=0;
	for(int i=max(0,(h*(h+1))/2-g);i<=r;i++) sum=(sum+a[i])%p;
	printf("%d",sum);
	return 0;
}