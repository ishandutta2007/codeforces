#include <iostream>
#define int long long
using namespace std;
int a[100];
string s=" codeforces";
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=10;i++)
		a[i]=1;
	while(1)
	{
		int s=1,mn=1e9;;
		for(int i=1;i<=10;i++)
			s*=a[i],mn=min(mn,a[i]);
		if(s>=n) break;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==mn)
			{
				++a[i];
				break;
			}
		}
	}
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=a[i];j++)
			cout << s[i];
	}
	return 0;
}