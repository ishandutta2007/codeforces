#include <iostream>
using namespace std;
int a[10000];
#define int long long
signed main(int argc, char** argv) {
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	for(int i=1;i<=k;i++)
	{
		char x;
		cin >> x;
		a[x]=1;
	}
	int now=0,ans=0;
	for(int i=0;i<s.size();i++)
	{
		if(a[s[i]])
			++now;
		else
		{
			ans+=now*(now+1)/2;
			now=0;
		}
	}
	ans+=now*(now+1)/2;
	cout << ans;
	return 0;
}