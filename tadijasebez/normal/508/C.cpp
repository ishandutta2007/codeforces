#include <stdio.h>
#include <map>
using namespace std;
const int N=10000;
map<int,bool> was;
map<int,bool>::iterator it;
int w[N];
int main()
{
	int n,t,r,i,j;
	bool bad=0;
	scanf("%i %i %i",&n,&t,&r);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&w[i]);
		int cnt=0;
		for(j=w[i]-t;j<w[i];j++)
		{
			cnt+=was[j];
		}
		for(j=w[i]-1;j>=w[i]-t;j--)
		{
			if(cnt<r && !was[j]) was[j]=1,cnt++;
		}
		if(cnt<r) bad=1;
	}
	if(bad) printf("-1\n");
	else
	{
		int sol=0;
		for(it=was.begin();it!=was.end();it++) sol+=it->second;
		printf("%i\n",sol);
	}
	return 0;
}