#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v[500005];
bool del[500005];
int Ans[500005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=i*2;j<=n;j+=i)v[i].push_back(j);
	int cnt=n;
	for(int i=n;i>=1;--i)if(v[i].size())
	{
		for(int x:v[i])
		{
			if(del[x])continue;
			else
			{
				del[x]=1;
				Ans[cnt]=i;
				--cnt;
			}
		}
	}
	for(int i=2;i<=n;++i)printf("%d ",Ans[i]);
}