#include<bits/stdc++.h>
using namespace std;
vector<int>a,b;
int main()
{
	int n,d,cur,cnt,sum=0;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(i==d)
			cur=x;
		else
			a.push_back(x);
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		b.push_back(x);
	}
	sort(b.begin(),b.end());
	cnt=b[b.size()-1];
	b.pop_back();
	cur+=cnt;
	int lb=0,ub=b.size()-1;
	for(int i=0;i<a.size();i++)
	{
		int k=a[i];
		if(k+b[lb]>cur)
		{
			ub--;
			sum++;
			continue;
		}
		else
			lb++;
	}
	printf("%d\n",sum+1);
	return 0;
}