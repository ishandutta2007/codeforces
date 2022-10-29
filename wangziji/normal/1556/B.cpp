#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
vector <int> v;
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int cnt=0,sum=0;
		v.clear();
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			a[i]&=1;
			cnt+=a[i];
			if(a[i]) sum+=a[i],v.push_back(i);
		}
		int qwq=0,S=0,ans=1e18;
		for(int i=1;i<=n;i+=2)
			++qwq;
		if(qwq==cnt)
		{
			int S=0;
			for(int i=0;i<v.size();i++)
				S+=max(i*2+1,v[i])-min(i*2+1,v[i]);
			ans=min(ans,S);
		}
		qwq=0,S=0;
		for(int i=2;i<=n;i+=2)
			++qwq,S+=i;
		if(qwq==cnt)
		{
			int S=0;
			for(int i=0;i<v.size();i++)
				S+=max(i*2+2,v[i])-min(i*2+2,v[i]);
			ans=min(ans,S);
		}
		if(ans>1e17) cout << "-1\n";
		else cout << ans << "\n";
	}
	return 0;
}