#include <iostream>
using namespace std;
int cnt[105],a[200005],lst[500005];
const int qwq=2e5;
int main(int argc, char** argv) {
	int n;
	cin >> n;
	int mx=0,d=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		mx=max(mx,++cnt[a[i]]);
		if(mx==cnt[a[i]]) d=a[i];
	}
	int ans=0;
	for(int i=1;i<=100;i++)
	{
		if(i!=d)
		{
			for(int j=qwq-n;j<=qwq+n;j++) lst[j]=1e9;
			int now=qwq;
			lst[qwq]=0;
			for(int j=1;j<=n;j++)
			{
				if(a[j]==d) --now;
				if(a[j]==i) ++now;
				if(lst[now]!=1e9) ans=max(ans,j-lst[now]);
				else lst[now]=j;
			}
		}
	}
	cout << ans;
	return 0;
}