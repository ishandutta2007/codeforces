#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> a[100005];
int cnt;
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		a[x].first=i;
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		a[x].second=i;
	}
	sort(a+1,a+n+1);
	int ans=0,mx=0;
	for(int i=1;i<=n;i++)
	{
		if(mx>a[i].second)
			++ans;
		mx=max(mx,a[i].second);
	}
	cout << ans;
	return 0;
}