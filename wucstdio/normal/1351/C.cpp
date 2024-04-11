#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
int t;
char ss[100005];
set<pair<pair<int,int>,pair<int,int> > >s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		s.clear();
		scanf("%s",ss+1);
		int x=0,y=0;
		int n=(int)strlen(ss+1);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int xx=x,yy=y;
			if(ss[i]=='N')x--;
			if(ss[i]=='S')x++;
			if(ss[i]=='E')y--;
			if(ss[i]=='W')y++;
			if(s.find(make_pair(make_pair(xx,yy),make_pair(x,y)))==s.end())ans+=5;
			else ans++;
			s.insert(make_pair(make_pair(xx,yy),make_pair(x,y)));
			s.insert(make_pair(make_pair(x,y),make_pair(xx,yy)));
		}
		printf("%d\n",ans);
	}
	return 0;
}