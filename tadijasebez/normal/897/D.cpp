#include <stdio.h>
int c,n,m;
int a[3000];
bool Solve()
{
	int x,i;
	scanf("%i",&x);
	fflush(stdout);
	if(x>c/2)
	{
		i=n;
		while(i>0 && a[i]>=x) i--;
		printf("%i\n",i);
		fflush(stdout);
		a[i]=x;
	}
	else
	{
		i=1;
		while(i<=n && a[i]!=0 && a[i]<=x) i++;
		printf("%i\n",i);
		fflush(stdout);
		a[i]=x;
	}
	bool done=1;
	for(i=1;i<=n;i++) if(a[i]==0) done=0;
	for(i=1;i<n;i++) if(a[i]>a[i+1]) done=0;
	return done;
}
int main()
{
	scanf("%i %i %i",&n,&m,&c);
	while(m--)
	{
		if(Solve()) break;
	}
	return 0;
}