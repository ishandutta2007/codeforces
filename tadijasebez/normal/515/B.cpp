#include <stdio.h>
const int N=105;
bool Happy[2][N];
int main()
{
	int n,m,x,i,cnt=0;
	scanf("%i %i",&n,&m);
	scanf("%i",&x);cnt+=x;
	while(x--) scanf("%i",&i),Happy[0][i]=1;
	scanf("%i",&x);cnt+=x;
	while(x--) scanf("%i",&i),Happy[1][i]=1;
	for(i=0;i<=100000000;i++)
	{
		int Boy=i%n;
		int Girl=i%m;
		if(Happy[0][Boy] && !Happy[1][Girl]) Happy[1][Girl]=1,cnt++;
		if(Happy[1][Girl] && !Happy[0][Boy]) Happy[0][Boy]=1,cnt++;
	}
	if(cnt==n+m) printf("Yes\n");
	else printf("No\n");
	return 0;
}