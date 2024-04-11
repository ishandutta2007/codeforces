#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define mp make_pair
pair<int,int> min(pair<int,int> a, pair<int,int> b){ return a>b?b:a;}
pair<int,int> max(pair<int,int> a, pair<int,int> b){ return a>b?a:b;}
int Read()
{
	char c=getchar();
	int x=0;
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
bool Inside(int x1, int y1, int x2, int y2, pair<int,int> point)
{
	if(point.first>=x1 && point.first<=x2 && point.second>=y1 && point.second<=y2) return true;
	return false;
}
#define ll long long
const int N=2050;
bool on[N];
int a[N][N],val[N][N],b[N][N],o[N];
ll dp[N][N];
pair<int,int> Min[N],Max[N];
pair<int,int> point[N][N];
vector<int> v[N];
ll sol;
char c;
int main()
{
	int n,m,k,x,y,q,i,j,x1,x2,y1,y2;
	n=Read();
	m=Read();
	k=Read();
	for(i=1;i<=k;i++)
	{
		on[i]=1;
		Min[i]=mp(N,N);
		o[i]=Read();
		for(j=1;j<=o[i];j++)
		{
			x=Read();
			y=Read();
			point[i][j]=mp(x,y);
			Min[i]=min(Min[i],mp(x,y));
			Max[i]=max(Max[i],mp(x,y));
			a[x][y]=i;
			b[x][y]=j;
			val[x][y]=Read();
			dp[i][j]=dp[i][j-1]+val[x][y];
		}
	}
	q=Read();
	while(q--)
	{
		for(c=getchar();c!='A' && c!='S';c=getchar());
		if(c=='A')
		{
			x1=Read();
			y1=Read();
			x2=Read();
			y2=Read();
			sol=0;
			for(i=1;i<=k;i++) v[i].clear();
			for(i=x1;i<=x2;i++)
			{
				if(on[a[i][y1]]) v[a[i][y1]].push_back(b[i][y1]);
				if(y2!=y1) if(on[a[i][y2]]) v[a[i][y2]].push_back(b[i][y2]);
			}
			for(i=y1+1;i<y2;i++)
			{
				if(on[a[x1][i]]) v[a[x1][i]].push_back(b[x1][i]);
				if(x1!=x2) if(on[a[x2][i]]) v[a[x2][i]].push_back(b[x2][i]);
			}
			for(i=1;i<=k;i++)
			{
				if(on[i])
				{
					//if(v[i].empty())
					//{
					//	if(Min[i]>=mp(x1,y1) && Max[i]<=mp(x2,y2)) sol+=dp[i][o[i]];
					//}
					//else
					//{
						if(Inside(x1,y1,x2,y2,point[i][1])) v[i].push_back(1);
						if(Inside(x1,y1,x2,y2,point[i][o[i]])) v[i].push_back(o[i]);
						sort(v[i].begin(),v[i].end());
						v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
						if(v[i].empty()) continue;
						for(j=0;j<v[i].size();j++)
						{
							sol+=dp[i][v[i][j]]-dp[i][v[i][j]-1];
							if(j+1==v[i].size())
							{
								//sol+=dp[i][v[i][j]]-dp[i][v[i][j]-1];
							}
							else
							{
								if(v[i][j]!=o[i] && Inside(x1,y1,x2,y2,point[i][v[i][j]+1]))
								{
									sol+=dp[i][v[i][j+1]-1]-dp[i][v[i][j]];
									//j++;
								}
								//else sol+=dp[i][v[i][j]]-dp[i][v[i][j]-1];
							}
						}
					//}
				}
				//printf("%i %lld\n",i,sol);
			}
			/*for(i=x1;i<=x2;i++)
			{
				for(j=y1;j<=y2;j++)
				{
					sol+=on[a[i][j]]?val[i][j]:0;
				}
			}*/
			printf("%lld\n",sol);
		}
		else
		{
			x=Read();
			on[x]^=1;
		}
	}
	return 0;
}