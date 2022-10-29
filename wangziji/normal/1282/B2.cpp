#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[200005],qzh[200005],qqzh[200005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m,p;
		memset(qzh,0,sizeof qzh);
		memset(qqzh,0,sizeof qqzh);
		cin >> n >> m >> p;
		for(int i=1;i<=n;i++) cin >> a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) qzh[i]=qzh[i-1]+a[i];
		for(int i=p;i<=n;i++) qqzh[i]=qqzh[i-p]+a[i];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(qzh[i%p]+qqzh[i]<=m)
				ans=max(ans,i);
		}
		cout << ans << endl;
	}
	return 0;
}