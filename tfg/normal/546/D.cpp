#include <iostream>
#include <cstdio>

typedef long long ll;

const int ms=int(5e6)+10;

ll f[ms];

int main()
{
	for(int i=2;i<ms;i++)
	{
		if(f[i])
			continue;
		for(int j=i;j<ms;j+=i)
		{
			int cur=j;
			while(cur%i==0)
			{
				cur/=i;
				f[j]++;
			}
		}
	}
	for(int i=1;i<ms;i++)
		f[i]+=f[i-1];

	int t;
	std::cin >> t;
	while(t--)
	{
		int r, l;
		scanf("%i %i",&r,&l);
		printf("%lli\n",f[r]-f[l]);
	}
}