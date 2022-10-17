#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=105;
int T,n,l,r,k;
int a[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&l,&r,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int s=0,t=0;
		for(int i=1;i<=n;i++)
			if(a[i]>=l&&a[i]<=r&&a[i]+s<=k)
				s+=a[i],t++;
		printf("%d\n",t);
	}
	return 0;
}