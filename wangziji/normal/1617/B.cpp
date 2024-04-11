#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int gcd(int x,int y)
{
	if(x>y) swap(x,y);
	while(x) y%=x,swap(x,y);
	return y;
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false),cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int flag=0;
		for(int c=1;!flag&&c<=n;c++)
		for(int i=1;i<=n-1;i++)
		{
			if(gcd(i,n-c-i)==c&&i!=c&&n-1-i!=c&&i!=n-c-i)
			{
				cout << i << " " << n-c-i << " " << c << "\n";
				flag=1;
				break;
			}
		}
	}
	return 0;
}