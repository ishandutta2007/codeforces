#include <stdio.h>
int a[30005],poseceno[30005];
int main()
{
	int n,t,i;
	scanf("%i%i",&n,&t);
	for(i=1;i<n;i++)
	{
		scanf("%i",&a[i]);
	}
	bool da=true;
	i=1;
	poseceno[1]=1;
	while(i!=n || da)
	{
		if(poseceno[i+a[i]]==0)
		{
			poseceno[i+a[i]]=1;
			i=i+a[i];
		}
		else da=false;
	}
	if(poseceno[t]==1) printf("YES");
	else printf("NO");
	return 0;
}