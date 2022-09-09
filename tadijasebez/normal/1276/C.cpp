#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=400050;
int val[N],sz[N],pre[N];
int main()
{
	int q,x;
	scanf("%i",&q);
	map<int,int> cnt;
	while(q--) scanf("%i",&x),cnt[x]++;
	vector<pair<int,int>> v;
	for(auto it:cnt) v.pb({it.second,it.first});
	sort(v.rbegin(),v.rend());
	for(int i=0;i<v.size();i++)
	{
		val[i+1]=v[i].second;
		sz[i+1]=v[i].first;
		pre[i+1]=pre[i]+sz[i+1];
	}
	int las=v.size(),ptr=las;
	int ans=0,n,m;
	for(int row=1;row<=pre[las];row++)
	{
		while(ptr && sz[ptr]<row) ptr--;
		int col=ptr+(pre[las]-pre[ptr])/row;
		if(col<row) break;
		if(ans<col*row)
		{
			ans=col*row;
			n=row;m=col;
		}
	}
	printf("%i\n",ans);
	printf("%i %i\n",n,m);
	auto nxt=[&](int &x, int &y)
	{

		y++;if(y==m) y=0;
		x++;if(x==n)
		{
			y-=n-1;
			if(y<0) y+=m;
			x=0;
		}
		//printf("%i %i\n",x,y);
	};
	vector<vector<int>> mat;
	mat.resize(n);
	for(int i=0;i<n;i++) mat[i].resize(m);
	int work=ans;
	for(int i=1,x=0,y=0;i<=las;i++)
	{
		int tmp=min(sz[i],n);
		tmp=min(tmp,work);
		while(tmp--)
		{
			work--;
			mat[x][y]=val[i];
			nxt(x,y);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) printf("%i ",mat[i][j]);
		printf("\n");
	}
	return 0;
}