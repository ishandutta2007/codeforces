#include <iostream>
#include <map>
using namespace std;
int a[300005];
map <int,int> mp;
int main(int argc, char** argv) {
	int T;
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		int n,mx=0,s=0;
		cin >> n;
		mp.clear();
		for(int i=1;i<=n;i++)
		{
			int x,y=0;
			cin >> x;
			a[i]=1;
			for(int j=2;j*j<=x;j++)
			{
				int cnt=0;
				while(x%j==0) cnt^=1,x/=j;
				if(cnt) a[i]*=j;
			}
			a[i]*=x;
			++mp[a[i]];
		}
		for(int i=1;i<=n;i++)
		{
			mx=max(mx,mp[a[i]]);
			if(mp[a[i]]%2==0) s+=mp[a[i]],mp[a[i]]=0;
		}
		if(mp[1])s+=mp[1];
		int q;
		cin >> q;
		while(q--)
		{
			long long x;
			cin >> x;
			if(x==0)
				cout << mx << '\n';
			else cout << max(mx,s) << "\n";
		}
	}
	return 0;
}