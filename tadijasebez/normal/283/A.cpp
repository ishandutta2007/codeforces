#include <bits/stdc++.h>
using namespace std;
#define ldb double
const int N=200050;
int a[N],add[N];
int main(){
	int q,n=1;
	ldb sum=0;
	scanf("%i",&q);
	while(q--){
		int t,x,y;
		scanf("%i",&t);
		if(t==1){
			scanf("%i %i",&x,&y);
			x=min(x,n);
			add[x]+=y;
			sum+=y*x;
		}else if(t==2){
			scanf("%i",&x);
			a[++n]=x;
			sum+=x;
		}else{
			sum-=a[n]+add[n];
			add[n-1]+=add[n];
			add[n]=0;
			n--;
		}
		printf("%.10f\n",sum/n);
	}
	return 0;
}