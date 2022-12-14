#include<cstdio>
#include<set>

using namespace std;

set<long long> se;

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	int ans=0;
	for(int i=0;i<N;i++)
	{
		int in;
		scanf("%d",&in);
		se.insert(in);
	}
	while(!se.empty())
	{
		int tmp=1;
		long long a=*se.begin();
		se.erase(a);
		while(true)
		{
			a*=K;
			if(se.count(a)==0) break;
			tmp++;
			se.erase(a);
		}
		ans+=(tmp+1)/2;
	}
	printf("%d\n",ans);
	return 0;
}