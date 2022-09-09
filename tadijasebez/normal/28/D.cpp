#include <bits/stdc++.h>
using namespace std;
const int N=100050;
const int inf=1e9+7;
map<pair<int,int>,pair<int,int>> dp;
int go[N];
int main()
{
	int n,v,c,l,r;
	scanf("%i",&n);
	int ans=0,cur=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%i %i %i %i",&v,&c,&l,&r);
		int tmp=-inf;
		if(l==0) tmp=v;
		if(dp.count({l,c+r})) tie(tmp,go[i])=dp[{l,c+r}],tmp+=v;
		dp[{l+c,r}]=max(dp[{l+c,r}],{tmp,i});
		if(r==0 && tmp>ans) ans=tmp,cur=i;
	}
	vector<int> out;
	while(cur) out.push_back(cur),cur=go[cur];
    reverse(out.begin(),out.end());
    printf("%i\n",out.size());
    for(int i:out) printf("%i ",i);
	return 0;
}