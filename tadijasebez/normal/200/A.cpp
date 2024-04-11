#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
const int N=2050;
const int inf=1e9+7;
bool rot;
int x,y;
int Dist(pair<int,int> a, pair<int,int> b){ return abs(a.first-b.first)+abs(a.second-b.second);}
pair<int,int> min(pair<int,int> a, pair<int,int> b)
{
	if(Dist(a,mp(x,y))<Dist(b,mp(x,y))) return a;
	else if(Dist(a,mp(x,y))>Dist(b,mp(x,y))) return b;
	if(!rot) return a<b?a:b;
	else return (a.second<b.second || a.second==b.second && a.first<b.first)?a:b;
}
int l[N][N],r[N][N];
bool used[N][N];
int FindL(int x, int y){ return !used[x][y]?y:l[x][y]=FindL(x,l[x][y]);}
int FindR(int x, int y){ return !used[x][y]?y:r[x][y]=FindR(x,r[x][y]);}
int main()
{
	int n,m,k,i,j;
	scanf("%i %i %i",&n,&m,&k);
	if(n>m) swap(n,m),rot=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(j!=1) l[i][j]=j-1;
			if(j!=m) r[i][j]=j+1;
		}
	}
	while(k--)
	{
		scanf("%i %i",&x,&y);
		if(rot) swap(x,y);
		pair<int,int> ans=mp(inf,inf);
		for(i=0;1;i++)
		{
            if((x+i>n && x-i<1) || (abs(ans.first-x)+abs(ans.second-y)<i)) break;
            if(x+i<=n)
			{
				if(!used[x+i][y]) ans=min(ans,mp(x+i,y));
				if(FindL(x+i,y)) ans=min(ans,mp(x+i,FindL(x+i,y)));
				if(FindR(x+i,y)) ans=min(ans,mp(x+i,FindR(x+i,y)));
			}
			if(x-i>=1)
			{
				if(!used[x-i][y]) ans=min(ans,mp(x-i,y));
				if(FindL(x-i,y)) ans=min(ans,mp(x-i,FindL(x-i,y)));
				if(FindR(x-i,y)) ans=min(ans,mp(x-i,FindR(x-i,y)));
			}
		}
		if(rot) printf("%i %i\n",ans.second,ans.first);
		else printf("%i %i\n",ans.first,ans.second);
		used[ans.first][ans.second]=1;
	}
	return 0;
}