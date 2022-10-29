#include <iostream>
#include <map>
#define int long long
using namespace std;
int a[200005],cnt[200005];
map <pair<int,int>,int> mp;
signed main(int argc, char** argv) {
	int n,ans=0;
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		ans+=a[i];
	}
	int q;
	cin >> q;
	while(q--)
	{
		int x,y,z;
		cin >> x >> y >> z;
		int t=mp[{x,y}];
		if(t)
		{
			--cnt[t];
			if(cnt[t]<a[t])
				++ans;
			mp[{x,y}]=0;
			//cout << t << " " << cnt[t] << " " << a[t] << endl;
		}
			++cnt[z],--ans;
			if(cnt[z]>a[z]) ++ans;
			mp[{x,y}]=z;
		cout << ans << endl;
	}
	return 0;
}