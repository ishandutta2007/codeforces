#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct Dis
{
	int d;
	int id;
}d[100005];
int n,pos[200005];
vector<int>s[200005];
bool cmp(Dis a,Dis b)
{
	return a.d>b.d;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i].d);
		d[i].id=i;
	}
	sort(d+1,d+n+1,cmp);
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		pos[i]=d[i].id*2-1;
		s[i+d[i].d-1].push_back(d[i].id*2);
		maxx=max(maxx,i+d[i].d-1);
	}
	for(int i=1;i<=maxx;i++)
	{
		if(!pos[i])
		{
			pos[i]=s[i-1][s[i-1].size()-1];
			s[i-1].pop_back();
		}
	}
	for(int i=1;i<=maxx;i++)
	{
		if(i!=maxx)printf("%d %d\n",pos[i],pos[i+1]);
		int n=(int)s[i].size();
		for(int j=0;j<n;j++)
		  printf("%d %d\n",pos[i],s[i][j]);
	}
	return 0;
}