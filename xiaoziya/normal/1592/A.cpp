#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=1005;
int T,n,m;
int a[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m); 
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int s=a[n]+a[n-1],k=m/s;
		m-=k*s;
		if(m==0)
			printf("%d\n",2*k);
		else if(m<=a[n])
			printf("%d\n",2*k+1);
		else printf("%d\n",2*k+2);
	}
	return 0;
}