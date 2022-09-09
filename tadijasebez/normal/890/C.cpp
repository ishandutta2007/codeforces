#include <stdio.h>
#include <vector>
using namespace std;
const int N=200050;
int c,Last[N];
vector<int> C[N];
int main()
{
	int n,i,x,Max=1;
	Last[0]=0;
	C[0].push_back(0);
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		if(!C[x].empty())
		{
			int pos=C[x].size()-1;
			int taj=C[x][pos];
			Last[taj]=i;
			C[x].pop_back();
			C[i].push_back(taj);
		}
		else
		{
			Last[++c]=i;
			C[i].push_back(c);
		}
	}
	printf("%i\n",c+1);
	return 0;
}