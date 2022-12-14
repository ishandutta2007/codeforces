#include<cstdio>
#include<set>

using namespace std;

set<int,greater<int> > se;

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int a;
		scanf("%d",&a);
		while(true)
		{
			if(se.find(a)==se.end())
			{
				se.insert(a);
				break;
			}
			se.erase(a);
			a++;
		}
	}
	printf("%d\n",*se.begin()+1-se.size());
	return 0;
}