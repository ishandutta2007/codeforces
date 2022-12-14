#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <map>
using namespace std;
#define N 200005
#define ll long long
int n,m,pri[30],tot,px[N],py[N];map<int ,int >mp[N];
void get_pri(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
		{
			pri[++tot]=i;
			while(x%i==0)x/=i;
		}
	if(x!=1)pri[++tot]=x;
}
bool check(int K)
{
	for(int i=1;i<=m;i++)
	{
		int x=(px[i]+K-1)%n+1,y=(py[i]+K-1)%n+1;
		if(mp[x].find(y)==mp[x].end())return 0;
	}return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);if(x>y)swap(x,y);
		mp[x][y]=mp[y][x]=1;px[i]=x,py[i]=y;
	}
	get_pri(n);
	for(int i=1;i<=tot;i++)if(check(n/pri[i]))return puts("Yes"),0;puts("No");
}