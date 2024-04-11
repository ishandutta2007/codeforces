#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100005;
int T,n;
int a[maxn<<2],b[maxn<<2],c[maxn<<2],d[maxn<<2];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		sort(a+1,a+1+n),sort(b+1,b+1+n);
		int suma=0,sumb=0;
		for(int i=n/4+1;i<=n;i++)
			suma+=a[i],sumb+=b[i];
		if(suma>=sumb){
			puts("0");
			continue;
		}
		int L=n,R=4*n+1;
		while(L+1<R){
			int mid=(L+R)>>1,exc=mid/4,A=0,B=0;
			for(int i=1;i<=n;i++)
				c[i]=a[i],d[i]=b[i];
			for(int i=n+1;i<=mid;i++)
				c[i]=100,d[i]=0;
			sort(c+1,c+1+mid),sort(d+1,d+1+mid);
			for(int i=exc+1;i<=mid;i++)
				A+=c[i],B+=d[i];
			if(A>=B)
				R=mid;
			else L=mid;
		}
		printf("%d\n",R-n);
	}
	return 0;
}