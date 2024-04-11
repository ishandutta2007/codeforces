#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int gcd(int x,int y)
{
	if(x>y) swap(x,y);
	while(x) y%=x,swap(x,y);
	return y;
}
int cnt[100];
signed main(int argc, char** argv) {
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			for(int j=1;j<=50;j++)
			{
				if(x&1) ++cnt[j];
				x>>=1;
			}
		}
		int ans=0;
		for(int i=1;i<=50;i++)
			ans=gcd(ans,cnt[i]);
		for(int i=1;i<=n;i++)
		{
			if(ans%i==0)
			{
				cout << i << " "; 
			}
		}
		cout << "\n";
	}
	return 0;
}