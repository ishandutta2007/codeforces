#include<stdio.h>
#include<string.h>
int n,m,l,r;
int i,j,ans;
int a[100020];
int b[100020];
int q[100020];
int main()
{
	scanf("%d %d %d %d",&n,&m,&r,&l);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	for(i=0;i<m;i++)
		scanf("%d",b+i);
	memset(q,-1,sizeof(q));
	for(i=0;i<n;i++)
	{
		while(a[i]>b[j]+r&&j<m)
			j++;
		if(a[i]>=b[j]-l&&a[i]<=b[j]+r&&j<m)
			q[i]=j++,ans++;
	}
	printf("%d\n",ans);
	for(i=0;i<n;i++)
		if(q[i]+1)
			printf("%d %d\n",i+1,q[i]+1);
	return 0;
}