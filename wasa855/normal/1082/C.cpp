#include<bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int sum[100005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m;
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
	}
	for(int i=1;i<=m;i++)
	{
		sort(v[i].begin(),v[i].end(),cmp);
	}
	for(int i=1;i<=m;i++)
	{
		int tmp=0;
		for(int j=0;j<v[i].size();j++)
		{
			tmp+=v[i][j];
			if(tmp<=0)
			{
				break;
			}
			sum[j+1]+=tmp;
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		if(sum[i]>maxn)
		{
			maxn=sum[i];
		}
	}
	cout<<maxn<<endl;
	return 0;
}