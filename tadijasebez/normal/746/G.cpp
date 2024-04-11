#include <stdio.h>
#include <vector>
using namespace std;
const int N=200050;
vector<int> row[N];
vector< pair<int,int> > ans;
int a[N];
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,t,k,i,j;
	scanf("%i %i %i",&n,&t,&k);
	for(i=1;i<=t;i++) scanf("%i",&a[i]);
	int sum=0,leaf=0;
	for(i=1;i<=t;i++)
	{
		sum+=a[i];
		leaf+=max(0,a[i]-a[i+1]);
	}
	if(leaf>k || sum!=n-1) 
	{
		printf("-1\n");
		return 0;
	}
	k-=leaf;
	int m=2;
	row[0].push_back(1);
	a[0]=1;
	for(i=1;i<=t;i++)
	{
		int l=min(k,row[i-1].size()-1);
		for(j=0;j<min(a[i],a[i-1]);j++)
		{
			if(j>0 && l>0)
			{
				ans.push_back(make_pair(row[i-1][0],m));
				row[i].push_back(m);
				m++;
				l--;
				k--;
			}
			else
			{
				ans.push_back(make_pair(row[i-1][j],m));
				row[i].push_back(m);
				m++;
			}
		}
		for(j=a[i-1];j<a[i];j++)
		{
			ans.push_back(make_pair(row[i-1][0],m));
			row[i].push_back(m);
			m++;
		}
	}
	if(k>0)
	{
		printf("-1\n");
		return 0;
	}
	printf("%i\n",n);
	for(i=0;i<ans.size();i++)
	{
		printf("%i %i\n",ans[i].first,ans[i].second);
	}
	return 0;
}