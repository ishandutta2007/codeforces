#include<bits/stdc++.h>
using namespace std;
int a1,a2,k1,k2,n;
int main(){
	scanf("%d%d%d%d%d",&a1,&a2,&k1,&k2,&n);
	int minn=0,maxn=0,nn=n;
	if(k1>k2){
		int k=min(n/k2,a2);
		maxn=k;
		n-=k*k2;
		maxn=maxn+min(n/k1,a1);
	}
	else{
		int k=min(n/k1,a1);
		maxn=k;
		n-=k*k1;
		maxn=maxn+min(n/k2,a2);
	}
	minn=nn-(k1-1)*a1-(k2-1)*a2;
	printf("%d %d\n",max(minn,0),maxn);
	return 0;
}