#include <iostream>
#include <algorithm>
using namespace std;
pair <int,int> a[2005],b[2005];
int ans[1000005];
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i].first >> a[i].second;
	for(int i=1;i<=m;i++)
		cin >> b[i].first >> b[i].second;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[j].first-a[i].first>=0)
			ans[max(0,b[j].first-a[i].first)]=max(ans[max(0,b[j].first-a[i].first)],b[j].second-a[i].second+1);
		}
	}
	for(int i=1000003;i>=0;i--) ans[i]=max(ans[i],ans[i+1]);
	int mn=1e9;
	for(int i=0;i<=1000004;i++) mn=min(mn,ans[i]+i);
//	for(int i=0;i<=10;i++)
//		cout << ans[i] << " ";
//	puts("");
	cout << mn;
	return 0;
}