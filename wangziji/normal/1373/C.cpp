#include <iostream>
using namespace std;
int qzh[1000005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string a;
		cin >> a;
		int n=a.size();
		a=' '+a;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='-') qzh[i]=qzh[i-1]-1;
			else qzh[i]=qzh[i-1]+1;
		}
		int now=1;
		long long ans=0;
		for(int i=0;i<=n;i++)
		{
			while(i>=-qzh[now]&&now<=n) ++now;
		//	cout << now << '\n';
			if(now==n+1)
			{
				ans+=n;
				break;
			}
			ans+=now;
		}
		cout << ans << "\n"; 
	}
	return 0;
}