#include <cstdio>

long long int mods[2][5];

int main()
{
	long long int n, m;
	scanf("%lli %lli", &n, &m);
	for(int i=1;(i-1)%5!=n%5;i++)
	{
		//printf("adicionando em %i caso base em %i.\n",i,0);
		mods[0][i]++;
	}
	for(int i=1;(i-1)%5!=m%5;i++)
	{
		//printf("adicionando em %i caso base em %i.\n",i,1);
		mods[1][i]++;
	}
	for(int i=0;i<5;i++)
	{
		mods[0][i]+=n/5;
		mods[1][i]+=m/5;
	}
	long long int ans=0;
	for(int i=0;i<5;i++)
	{
		ans+=mods[0][i]*mods[1][(5-i)%5];
	}
	printf("%lli",ans);
}