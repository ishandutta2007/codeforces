#include<stdio.h>
int v[1020][1020];
int c[1020],n,m,x,y,a,b;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d %d",&x,&y),c[y]++,v[x][y]++;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		if(v[x][y])
			b++,v[x][y]--;
		if(c[y])
			a++,c[y]--;
	}
	printf("%d %d",a,b);
	return 0;
}