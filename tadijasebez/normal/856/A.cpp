#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
/*vector<int> primes;
bool sieve[1000050];
void FindPrimes()
{
	int i,j;
	//primes.push_back(1);
	for(i=2;i<1000050;i++)
	{
		if(!sieve[i])
		{
			primes.push_back(i);
			for(j=i;j<1000050;j+=i)
				sieve[j]=true;
		}
	}
}*/
bool used[2000050];
vector<int> sol,back;
int a[150];
int main()
{
	int t,n,i,c,j;
	bool ok,ok1;
	//FindPrimes();
	scanf("%i",&t);
	while(t--)
	{
		scanf("%i",&n);
		for(i=0;i<n;i++)
		{
			scanf("%i",&a[i]);
			//if(used[a]) ok=false;
			//used[a]=true;
			//back.push_back(a);
		}
		//sort(a,a+n);
		//ok1=true;
		//for(i=0;i<n-1;i++)
		//{
		//	if(a[i]==a[i+1]) ok1=false;
		//}
		c=0;
		j=1;
		while(c<n && j<=1000000)
		{
			ok=true;
			for(i=0;i<n;i++)
			{
				if(used[a[i]+j])
				{
					ok=false;
					break;
				}
			}
			if(ok)
			{
				sol.push_back(j);
				for(i=0;i<n;i++)
				{
					used[a[i]+j]=true;
					back.push_back(a[i]+j);
				}
				c++;
			}
			j++;
		}
		if(c==n)// && ok1)
		{
			printf("YES\n");
			for(i=0;i<sol.size();i++)
			{
				printf("%i ",sol[i]);
			}
			printf("\n");
		}
		else printf("NO\n");
		for(i=0;i<back.size();i++) used[back[i]]=false;
		back.clear();
		sol.clear();
	}
	return 0;
}