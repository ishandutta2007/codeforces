#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool Map[3][N];
int main()
{
	int n,q,cnt=0;
	scanf("%d%d",&n,&q);
	while(q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int s=Map[a^3][b-1]+Map[a^3][b]+Map[a^3][b+1];
		if(Map[a][b])
		{
			Map[a][b]=false;
			cnt-=s;
		}
		else
		{
			Map[a][b]=true;
			cnt+=s;
		}
		if(!cnt&&!Map[1][1]&&!Map[2][n]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}