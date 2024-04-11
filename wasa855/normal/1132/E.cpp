#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10];
int ans;
void dfs(int dep,int w)
{
//	cout<<dep<<" "<<w<<endl;
	if(dep==9)
	{
		if(w<ans) ans=w;
		return ;
	}
	int res=min(a[dep],w/dep);
	for(int i=0;i<=8;i++)
	{
		if(res-i<0) break;
		dfs(dep+1,w-dep*(res-i));
	}
}
signed main()
{
	int n;
	cin>>n;
	ans=n;
	for(int i=1;i<=8;i++) cin>>a[i];
	int sum=0;
	for(int i=1;i<=8;i++) sum+=(i*a[i]);
	if(sum<=n)
	{
		cout<<sum<<endl;
		return 0;
	}
	dfs(1,n);
	cout<<(n-ans)<<endl;
	return 0;
}