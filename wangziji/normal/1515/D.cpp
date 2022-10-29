#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int a[200005],cnt[500005];
const int qwq=205000;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,l,r;
		cin >> n >> l >> r;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			cnt[i]=cnt[i+qwq]=0;
		if(l>r) for(int i=l+1;i<=n;i++) a[i]+=qwq;
		else for(int i=1;i<=l;i++) a[i]+=qwq;
		if(l<r) swap(l,r);
		for(int i=1;i<=n;i++)
			++cnt[a[i]];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=qwq) while(cnt[a[i]]&&cnt[a[i]+qwq])
				--cnt[a[i]],--cnt[a[i]+qwq],--l,--r;
		}
		for(int i=1;i<=n;i++)
		{
			while(cnt[i]>=2&&l>r)
				l-=2,cnt[i]-=2,++ans;
		}
		ans+=l;
		cout << ans << "\n";
	}
	return 0;
}