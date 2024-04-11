#include <iostream>
#include <map>
using namespace std;
map <pair<int,int>,int> mp;
int a[1005],b[1005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		mp.clear();
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			cin >> b[i];
		for(int i=1;i<=n;i++)
		{
			if(a[i]>a[n-i+1]) swap(a[i],a[n-i+1]);
			++mp[{a[i],a[n-i+1]}];
		}
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(b[i]>b[n-i+1]) swap(b[i],b[n-i+1]);
			if(mp[{b[i],b[n-i+1]}]<=0)
			{
				flag=0;
				break;
			}
			--mp[{b[i],b[n-i+1]}];
		}
		if(flag) puts("yes");
		else puts("no");
	}
	return 0;
}