#include<bits/stdc++.h>
#define maxn 55
using namespace std;
int n;
int a[maxn],b[maxn];
vector< vector<int> > Ans;
void work(vector<int> d)
{
	int p=n;
	int cnt=0;
	for(int x:d)
	{
		for(int i=p-x+1;i<=p;++i)b[i]=a[++cnt];
		p-=x;
	}
	for(int i=1;i<=n;++i)a[i]=b[i];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int ans=0;
	while(1)
	{
		bool yes=1;
		for(int i=2;i<=n;++i)if(a[i-1]>a[i])yes=0;
		if(yes)break;
		++ans;
		vector<int> tmp;tmp.clear();
		if(ans&1)
		{
			int D=1;
			for(int i=2;i<=n;++i)
			{
				if(a[i-1]<a[i])D++;
				else
				{
					tmp.push_back(D);
					D=1;
				}
			}
			tmp.push_back(D);
		}
		else
		{
			int D=1;
			for(int i=2;i<=n;++i)
			{
				if(a[i-1]>a[i])D++;
				else
				{
					tmp.push_back(D);
					D=1;
				}
			}
			tmp.push_back(D);
		}
		work(tmp);
		Ans.push_back(tmp);
	}
	printf("%d\n",ans);
	for(vector<int> t:Ans)
	{
		printf("%d ",t.size());
		for(int x:t)printf("%d ",x);
		puts("");
	}
}