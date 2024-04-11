#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const int N=3050;
char s[N][N];
int l[N][N],r[N][N],n,m;
ll ans;
struct BIT
{
	int sum[N];
	BIT(){ for(int i=0;i<N;i++) sum[i]=0;}
	void Set(int i, int f){ for(;i<N;i+=i&-i) sum[i]+=f;}
	int Get(int i){ int ans=0;for(;i;i-=i&-i) ans+=sum[i];return ans;}
	int Get(int l, int r){ l=max(l,1);return Get(r)-Get(l-1);}
} QS;
void Solve(int x, int y)
{
	//printf("%i %i\n",x,y);
	vector<vector<pair<int,int> > > intervals;
	bool was=0;
	for(int i=0;y-i>0 && x+i<=n;i++)
	{
		if(s[x+i][y-i]=='z')
		{
			if(!was)
			{
				intervals.pb(vector<pair<int,int> >(0));
			}
			intervals[intervals.size()-1].pb(mp(x+i,y-i));
			was=1;
		}
		else was=0;
	}
	for(auto v:intervals)
	{
            set<pair<int,int> > del;
            for(int i=0;i<v.size();i++)
		{
			QS.Set(i+1,1);
			int x=v[i].first;
			int y=v[i].second;
			//printf("%i (%i %i)\n",i,x,y);
			del.insert(mp(y-l[x][y]+1,i+1));
			while(del.size() && del.rbegin()->first>y)
			{
				pair<int,int> p=*del.rbegin();
				QS.Set(p.second,-1);
				del.erase(p);
			}
			ans+=QS.Get(i+1-r[x][y]+1,i+1);
			//printf("ans:%lld\n",ans);
		}
		for(auto p:del) QS.Set(p.second,-1);
	}
}
int main()
{
	int i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++)
	{
		if(s[i][j]=='z') l[i][j]=l[i][j-1]+1;
	}
	for(i=1;i<=n;i++) for(j=m;j>=1;j--)
	{
		if(s[i][j]=='z') r[i][j]=r[i][j+1]+1;
	}
	for(j=1;j<=m;j++) Solve(1,j);
	for(i=2;i<=n;i++) Solve(i,m);
	printf("%lld\n",ans);
	return 0;
}