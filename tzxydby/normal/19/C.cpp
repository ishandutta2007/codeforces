#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int P=20040911;
int a[N],h[N],p[N],rmp[N],n,cnt,ans;
vector<int>v[N];
vector<pair<int,int>>del;
map<int,int>mp; 
bool same(int x,int y)
{
	int xe=y-1,ye=2*y-x-1;
	if(ye>n)
		return false;
	int hx=h[xe]-h[x-1]*p[y-x],hy=h[ye]-h[y-1]*p[y-x];	
	return hx==hy;		
}
int main()
{
	p[0]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(mp.find(x)!=mp.end())
			a[i]=mp[x];
		else
		{
			mp[x]=++cnt;
			a[i]=cnt;
			rmp[cnt]=x;
		}
		p[i]=p[i-1]*P;
		v[a[i]].push_back(i);
		h[i]=h[i-1]*P+a[i];
	} 
	for(int i=1;i<=cnt;i++)
		for(int j=0;j<v[i].size();j++)
			for(int k=j+1;k<v[i].size();k++)
				if(same(v[i][j],v[i][k]))
					del.push_back(make_pair(v[i][k]-v[i][j],v[i][j]));
	sort(del.begin(),del.end());
	for(int i=0;i<del.size();i++)
		if(del[i].second>ans)
			ans=del[i].second+del[i].first-1;
	printf("%d\n",n-ans);
	for(int i=ans+1;i<=n;i++)
		printf("%d ",rmp[a[i]]);
	printf("\n");
	return 0;
}