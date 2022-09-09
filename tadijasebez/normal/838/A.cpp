#include <stdio.h>
#include <vector>
using namespace std;
bool Sieve[2500];
vector<int> primes;
const int MaxN=50;
void FindPrimes()
{
	int i,j;
	for(i=2;i<MaxN;i++)
	{
		if(!Sieve[i])
		{
			primes.push_back(i);
			for(j=i;j<MaxN;j+=i)
			{
				Sieve[j]=true;
			}
		}
	}
}
int Matrix[2505][2505];
char c[2505];
int Res[2505][2505];
int min(int a, int b)
{
	if(a>b) return b;
	else return a;
}
int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}
const int inf=1e9;
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%s",&c);
		for(j=0;j<m;j++)
		{
			Matrix[i][j]=c[j]-'0';
		}
	}
	FindPrimes();
	int sol=inf;
	vector<int>::iterator it;
	for(it=primes.begin();it!=primes.end();it++)
	{
		int x=*it,tr=0;
		if(x>max(n,m)) break;
		for(i=0;i<=n/x;i++)
		{
			for(j=0;j<=m/x;j++)
			{
				Res[i][j]=0;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				Res[i/x][j/x]+=Matrix[i][j];
			}
		}
		for(i=0;i<=n/x;i++)
		{
			for(j=0;j<=m/x;j++)
			{
				tr+=min(Res[i][j],x*x-Res[i][j]);
				//printf("%i ",tr);//,Res[i][j]);
			}
			//printf("\n");
		}
		//printf("%i %i\n",x,tr);
		sol=min(sol,tr);
	}
	printf("%i\n",sol);
	return 0;
}