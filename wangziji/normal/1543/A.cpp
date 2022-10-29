#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		long long a,b;
		cin >> a >> b;
		if(a==b)
		{
			cout << "0 0\n";
		}
		else
		{
			long long t=max(a,b)-min(a,b);
			cout << t;
			cout << " " << min(a%t,t-a%t) << "\n";
		}
	}
	return 0;
}