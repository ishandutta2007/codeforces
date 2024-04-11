#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int ans,sol,tmp;
vector<int> v;
int main()
{
	int n,s,i,x;
	scanf("%i %i",&n,&s);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		if(i==s)
		{
			if(x!=0) ans++;
		}
		else
		{
			if(x==0) tmp++,ans++;
			else v.push_back(x);
		}
	}
	sort(v.begin(),v.end());
	int j=0;
	for(i=1;i<=n;i++)
	{
		while(j+sol<v.size() && v[j]<i) j++;
		if(j+sol==v.size()) break;
		if(v[j]!=i)
		{
			if(tmp) tmp--;
			else sol++;
		}
	}
	printf("%i\n",sol+ans);
	return 0;
}