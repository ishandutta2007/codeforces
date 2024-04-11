#include<bits/stdc++.h>
using namespace std;
const int N=200005;
map<pair<int,int>,int>las;
int n,t,x,y,ans,al,ar;
char s[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		x=0,y=0,al=0,ar=1e9;
		las.clear();
		las[make_pair(0,0)]=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='L')
				x--;
			if(s[i]=='R')
				x++;
			if(s[i]=='U')
				y++;
			if(s[i]=='D')
				y--;
			if(las.find(make_pair(x,y))==las.end())
				las[make_pair(x,y)]=i;
			else
			{
				if(ar==1e9||i-las[make_pair(x,y)]<ar-al+1)
				{
					ar=i;
					al=las[make_pair(x,y)]+1;
				}
				las[make_pair(x,y)]=i;
			}
		}
		if(ar==1e9)
			puts("-1");
		else
			printf("%d %d\n",al,ar);
	}
	return 0;
}