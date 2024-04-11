#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int inf=1000000000;
vector<int> vec;
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int b[105];
int main()
{
	int n,i,j,k;
	scanf("%i",&n);
	for(i=0;i<n*2;i++) scanf("%i",&b[i]);
	int sol=inf,ans;
	for(i=0;i<n*2;i++)
	{
		for(j=i+1;j<n*2;j++)
		{
			ans=0;
			vec.clear();
			for(k=0;k<n*2;k++)
			{
				if(k!=i && k!=j) vec.push_back(b[k]);
			}
			sort(vec.begin(),vec.end());
			for(k=0;k<vec.size();k+=2) ans+=vec[k+1]-vec[k];
			//for(k=0;k<vec.size();k++) printf("%i ",vec[k]);
			//printf("\n");
			sol=min(sol,ans);
		}
	}
	printf("%i\n",sol);
	return 0;
}