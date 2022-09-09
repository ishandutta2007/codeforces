#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=50;
int col[N];
int main()
{
	int n,x,i,y;char s[10];
	vector<pair<int,int> > p;
	scanf("%i",&n);
	int pos=1e9-1,sz=1<<29;
	for(i=1;i<=n;i++)
	{
		printf("%i %i\n",pos,pos);
		fflush(stdout);
		scanf("%s",s);
		if(s[0]=='b') col[i]=1;
		else col[i]=0;
		p.pb(mp(pos,col[i]));
		sz=sz/2;
		if(col[i]==col[1])
		{
			pos-=sz;
			//printf("pos:%i sz:%i\n",pos,sz);
		}
		else pos+=sz;
	}
	sort(p.begin(),p.end());
	col[n+1]=-1;
	for(i=0;i<p.size();i++)
	{
		if(i+1==p.size() || p[i].second!=p[i+1].second)
		{
			printf("%i %i %i %i\n",p[i].first,p[i].first+1,p[i].first+1,p[i].first);
			fflush(stdout);
			return 0;
		}
	}
	return 0;
}