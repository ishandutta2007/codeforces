
 #include<stdio.h>
int main()
{
	int t,l,r;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&l,&r);
		printf("%d %d\n",l,2*l);
	}
}