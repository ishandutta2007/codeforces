#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],b[N];
vector<int>v,t[N];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		t[a[i]].push_back(b[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(t[i].size())
			k--;
		else
			continue;
		sort(t[i].begin(),t[i].end());
		for(int j=0;j<t[i].size()-1;j++)
			v.push_back(t[i][j]);
	}
	sort(v.begin(),v.end());
	long long ans=0;
	for(int i=0;i<k;i++)
		ans+=v[i];
	printf("%I64d\n",ans);
	return 0;
}