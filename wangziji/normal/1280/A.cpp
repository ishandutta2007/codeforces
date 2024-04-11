#include <iostream>
#define int long long
#define mod 1000000007
using namespace std;
string a;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int x;
		cin >> x >> a;
		int l=0,ans=a.size(),flag=0;
		for(int i=1;i<=x;i++)
		{
			++l;
			if(a.size()<=x)
			{
			    string b=a.substr(l);
				for(int j=1;j<a[l-1]-48;j++)
					a+=b;
			}
			ans+=((int)a[l-1]-49)*(ans-l);
			ans%=mod;
		}
		cout << (ans+mod)%mod << endl;
	}
	return 0;
}