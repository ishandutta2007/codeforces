#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	int n;
	scanf("%d",&n);
	int l=1,r=n;
	int kk=0;
	while(r-l>1){
		int mid=(r+l)>>1;
		printf("+ %d\n",n-mid);
		fflush(stdout);
		int d;
		scanf("%d",&d);
		if(d>kk)l=mid;
		else r=mid;
		l=(l+n-mid)%n,r=(r+n-mid)%n;
		if(r==0)r=n;
		kk=d;
	}
	printf("! %d\n",kk*n+l);
	return 0;
}