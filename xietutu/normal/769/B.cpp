#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct xy
{
	int x,id;
}a[1000];

bool cmp(const xy &X,const xy &Y)
{
	return X.x>Y.x;
}

vector<pair<int,int> > ans;

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].x);
		a[i].id=i;
	}
	sort(a+2,a+n+1,cmp);
	int st=2;
	for (int i=1;i<=n;i++)
	if (st>i)
	{
		for (int j=st;j<=min(n,st+a[i].x-1);j++) ans.push_back(make_pair(a[i].id,a[j].id));	
		st=min(st+a[i].x,n+1);
	}
	if (st!=n+1) printf("-1\n");
	else
	{
		printf("%d\n",(int)ans.size());
		for (int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}