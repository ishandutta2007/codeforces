#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n,k,now=0;
		cin >> n >> k;
		for(int i=0;i<n;i++)
		{
			int x=now^i;
			cout << x << endl;
			now^=x;
			int t;
			cin >> t;
			if(t==1) break;
		}
	}
	return 0;
}