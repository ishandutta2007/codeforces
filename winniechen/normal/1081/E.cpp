#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define ll long long
#define N 200005
ll a[N],squ[N];
int ans[N],n,t[N];
bool check(ll x)
{
	int p=lower_bound(squ+1,squ+200001,x)-squ;
	if(squ[p]==x)return 1;return 0;
}
vector<int>v[N];
void work()
{
	int now=0;
	for(int i=2;i<=n;i+=2)
	{
		int flg=0;
		int p,lim=v[a[i]].size();
		for(int j=0;j<lim;j++)
		{
			int x=a[i]/v[a[i]][j];
			if((v[a[i]][j]^x)&1)continue;
			if((v[a[i]][j]-x)/2>now){p=(v[a[i]][j]-x)/2;flg=(v[a[i]][j]+x)/2;break;}
		}
		if(!flg)return ;
		a[i-1]=squ[p]-squ[now];
		now=flg;
	}
	puts("Yes");
	for(int i=1;i<=n;i++)printf("%lld ",a[i]);puts("");exit(0);
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i+=2)scanf("%lld",&a[i]);
	for(int i=1;i<=200000;i++)squ[i]=(ll)i*i;
	for(int i=1;i<=200000;i++)
	{
		for(int j=1;j*j<=i;j++)
			if(i%j==0)
			{
				v[i].push_back(j);
				if(j*j!=i)v[i].push_back(i/j);
			}
		sort(v[i].begin(),v[i].end());
	}
	work();
	puts("No");
}