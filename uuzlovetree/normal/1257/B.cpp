#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
ll x,y;
map<ll,bool> vis;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		vis.clear();
		scanf("%I64d%I64d",&x,&y);
		while(!vis[x])
		{
			if(x>=y)break;
			vis[x]=1;
			if(x&1)x--;
			x=x*3/2;
		}
		if(x>=y)puts("YES");
		else puts("NO");
	}
}