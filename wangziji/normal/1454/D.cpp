#include <iostream>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		long long n;
		cin >> n;
		long long mx=1,pos=n;
		for(long long i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				long long t=n,qwq=0;
				while(t%i==0) ++qwq,t/=i;
				if(qwq>mx) mx=qwq,pos=i;
			}
		}
		cout << mx << "\n";
		while(n%pos==0)
		{
			n/=pos;
			if(n%pos==0)
				cout << pos << " ";
			else cout << n*pos << "\n";
		}
	}
	return 0;
}