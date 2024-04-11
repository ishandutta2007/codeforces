#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
set<int> SQ;
set<int>::iterator it;
int min(int a, int b){ return a>b?b:a;}
const int N=200050;
int a[N];
int main()
{
	int num=0,n,i;
	for(i=0;i*i<1e9;i++) SQ.insert(i*i);
	SQ.insert(i*i);
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(SQ.count(a[i])) num++;
	}
	if(num>n/2)
	{
		int cnt=0;//,cnt1=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==0) cnt++;
		}
		int g=num-(n/2);
		int sol=g;
		if(cnt>n/2)
		{
			sol+=cnt-(n/2);
		}
		printf("%i\n",sol);
	}
	else
	{
		vector<int> ans;
		for(i=1;i<=n;i++)
		{
			if(!SQ.count(a[i]))
			{
				it=SQ.lower_bound(a[i]);
				int tmp=(*it)-a[i];
				it--;
				int tmp2=a[i]-(*it);
				ans.push_back(min(tmp,tmp2));
			}
		}
		ll sol=0;
		sort(ans.begin(),ans.end());
		for(i=0;i+num+1<=n/2;i++)
		{
			sol+=ans[i];
		}
		printf("%lld\n",sol);
	}
	return 0;
}