#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[105];
inline int check(int x)
{
	if(x<=1) return 0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return 1;
	return 0;
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int sum=0;
		for(int i=1;i<=n;i++) sum+=a[i];
		if(check(sum))
		{
			cout << n << "\n"; 
			for(int i=1;i<=n;i++)
				cout << i << " ";
			cout << "\n";
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(check(sum-a[i]))
				{
					cout << n-1 << "\n";
					 for(int j=1;j<=n;j++)
					 {
					 	if(j!=i)
					 		cout << j << " ";
					 }
					 cout << "\n";
					 break;
				}
			}
		}
	}
	return 0;
}