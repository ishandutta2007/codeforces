// CF 822C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
vector<pair<int,int> > v[444444];
vector<int> ss[444444];
int main()
{
	int n,x,i,j,k,si,sp,p,l,r,c;
	LL ans;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i=i+1)
	{
		scanf("%d%d%d",&l,&r,&c);
		r=r-l+1;
		v[r].push_back(make_pair(l,c));
	}
	ans=(LL)1<<40;
	for(i=1;i<=x;i=i+1){
		sort(v[i].begin(),v[i].end());
		si=v[i].size();
		for(j=0;j<si;j=j+1)
			ss[i].push_back(v[i][j].second);
		for(j=si-2;j>=0;j=j-1)
			ss[i][j]=min(v[i][j].second,ss[i][j+1]);
	}
	for(i=1;i<x;i=i+1){
		p=x-i;
		si=v[i].size();
		sp=v[p].size();
		j=0;
		k=0;
		while(j<si&&k<sp){
			if(v[i][j].first+i<=v[p][k].first){
				ans=min(ans,(LL)v[i][j].second+ss[p][k]);
				j++;
			}
			else
				k++;
		}
	}
	if(ans==(LL)1<<40)
		ans=-1;
	cout<<ans<<endl;
	return 0;
}