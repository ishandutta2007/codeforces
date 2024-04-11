#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int> primes;
int factor[10100100];

int num[100100],den[100100];
int ncnt[10100100],dcnt[10100100];
int ord1[10100100],ord2[10100100];

int ndiv[100100],ddiv[100100];

int main()
{
	int N,M;
	memset(factor,-1,sizeof(factor));
	factor[1]=1;
	for(int i=2;i<10100100;i++)
	{
		if(factor[i]==-1)
		{
			factor[i]=i;
			primes.push_back(i);
			for(int j=2;i*j<10100100;j++)
			{
				factor[i*j]=i;
			}
		}
	}
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d",num+i);
	for(int i=0;i<M;i++) scanf("%d",den+i);
	for(int i=0;i<N;i++)
	{
		int tmp=num[i];
		while(tmp!=1)
		{
			int p=factor[tmp];
			ncnt[p]++;
			tmp/=p;
		}
	}
	for(int i=0;i<M;i++)
	{
		int tmp=den[i];
		while(tmp!=1)
		{
			int p=factor[tmp];
			dcnt[p]++;
			tmp/=p;
		}
	}
	for(int i=0;i<primes.size();i++)
	{
		ord1[primes[i]]=min(ncnt[primes[i]],dcnt[primes[i]]);
		ord2[primes[i]]=min(ncnt[primes[i]],dcnt[primes[i]]);
	}
	for(int i=0;i<N;i++)
	{
		int tmp=num[i];
		ndiv[i]=1;
		while(tmp!=1)
		{
			int p=factor[tmp];
			tmp/=p;
			if(ord1[p]>=1)
			{
				ndiv[i]*=p;
				ord1[p]--;
			}
		}
	}
	for(int i=0;i<M;i++)
	{
		int tmp=den[i];
		ddiv[i]=1;
		while(tmp!=1)
		{
			int p=factor[tmp];
			tmp/=p;
			if(ord2[p]>=1)
			{
				ddiv[i]*=p;
				ord2[p]--;
			}
		}
	}
	printf("%d %d\n",N,M);
	for(int i=0;i<N;i++)
	{
		printf("%d%c",num[i]/ndiv[i],i==N-1?'\n':' ');
	}
	for(int i=0;i<M;i++)
	{
		printf("%d%c",den[i]/ddiv[i],i==M-1?'\n':' ');
	}
	return 0;
}