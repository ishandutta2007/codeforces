#include <stdio.h>
const int N=1550;
int n,a,b;
bool vis[N];
int main()
{
	int k1,k2,k3,i,j,l;
	scanf("%i %i %i",&k1,&k2,&k3);
	if(k1>=k2 && k1>=k3) n=k1,a=k2,b=k3;
	else if(k2>=k1 && k2>=k3) n=k2,a=k1,b=k3;
	else if(k3>=k1 && k3>=k2) n=k3,a=k1,b=k2;
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			bool ok=1;
			for(l=1;l<n;l++) if(l%a!=i && l%b!=j){ ok=0;break;}
			if(ok) for(l=n+1;l<n*2;l++) if(l%a!=i && l%b!=j){ ok=0;break;}
			if(ok) return printf("YES\n"),0;
		}
	}
	printf("NO\n");
	return 0;
}