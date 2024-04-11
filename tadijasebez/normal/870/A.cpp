#include <stdio.h>
bool a[10],b[10];
int ma=10,mb=10;
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,m,i,x;
	scanf("%i %i",&n,&m);
	for(i=0;i<n;i++) scanf("%i",&x),a[x]=true,ma=min(ma,x);
	for(i=0;i<m;i++) scanf("%i",&x),b[x]=true,mb=min(mb,x);
	for(i=1;i<10;i++) if(a[i] && b[i]) return printf("%i\n",i),0;
	printf("%i%i\n",min(ma,mb),max(ma,mb));
 	return 0;
}