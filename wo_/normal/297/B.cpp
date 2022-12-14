#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int alice[200200],bob[200200];

vector<int> a,b;

int types[200200];

int main()
{
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<N;i++)
	{
		int in;
		scanf("%d",&in);
		a.push_back(in);
		types[i]=in;
	}
	for(int i=0;i<M;i++)
	{
		int in;
		scanf("%d",&in);
		b.push_back(in);
		types[i+N]=in;
	}
	sort(types,types+N+M);
	int ln=unique(types,types+N+M)-types;
	for(int i=0;i<N;i++)
	{
		int id=lower_bound(types,types+ln,a[i])-types;
		alice[id]++;
	}
	for(int i=0;i<M;i++)
	{
		int id=lower_bound(types,types+ln,b[i])-types;
		bob[id]++;
	}
	int asum=0,bsum=0;
	for(int i=ln-1;i>=0;i--)
	{
		asum+=alice[i],bsum+=bob[i];
		if(asum>bsum)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}