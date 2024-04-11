#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string a;
		cin >> a;
		int n=a.size();
		a=' '+a;
		int now=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='0') ++now;
			else
			{
				int x=0;
				for(int j=i;j<=n;j++)
				{
					x*=2;
					x+=a[j]-'0';
					++now;
					if(x<=now) ++ans;
					if(x>=1e6) break;
				}
				now=0;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}