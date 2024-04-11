#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1550;
map<int,vector<pair<int,int>>> all;
int a[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++)
	{
		int x=0;
		for(j=i;j<=n;j++)
		{
			x+=a[j];
			all[x].pb({i,j});
		}
	}
	vector<pair<int,int>> ans;
	for(auto it:all)
	{
		vector<pair<int,int>> v=it.second;
		vector<pair<int,int>> tmp;
		sort(v.begin(),v.end());
		tmp.pb(v[0]);
		for(int i=1;i<v.size();i++)
		{
			if(v[i].first>tmp.back().second) tmp.pb(v[i]);
			else if(v[i].second<tmp.back().second) tmp[tmp.size()-1]=v[i];
		}
		if(ans.size()<tmp.size()) ans=tmp;
	}
	printf("%i\n",ans.size());
	for(auto p:ans) printf("%i %i\n",p.first,p.second);
	return 0;
}