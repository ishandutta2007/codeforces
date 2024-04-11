#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
pair <int,int> a[5005];
int ans[5005],cnt,vis[5005],n,p[5005];
inline long long dis(int x,int y)
{
	return (a[x].first-a[y].first)*(a[x].first-a[y].first)+(a[x].second-a[y].second)*(a[x].second-a[y].second);
}
inline void dfs()
{
	if(cnt>=3)
	{
		if(dis(ans[cnt-2],ans[cnt-1])<=dis(ans[cnt-2],ans[cnt])-dis(ans[cnt-1],ans[cnt]))
			return ;
	}
	if(cnt==n)
	{
		for(int i=1;i<=n;i++)
			cout << ans[i] << " ";
		exit(0);
	}
	for(int I=1;I<=n;I++)
	{
		int i=p[I];
		if(!vis[i])
			vis[i]=1,ans[++cnt]=i,dfs(),--cnt,vis[i]=0;
	}
}
signed main(int argc, char** argv) {
	cin >> n;
	srand((unsigned long long)new char);
	for(int i=1;i<=n;i++) p[i]=i;
	random_shuffle(p+1,p+n+1);
	for(int i=1;i<=n;i++)
		cin >> a[i].first >> a[i].second;
	dfs();
	return 0;
}