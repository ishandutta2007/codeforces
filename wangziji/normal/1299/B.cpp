#include <iostream>
#include <map>
#define int long long
using namespace std;
map <pair <int,int> ,int> mp;
pair <int,int> a[100005];
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	int sx=0,sy=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].first >> a[i].second;
		mp[a[i]]=1;sx+=a[i].first,sy+=a[i].second;
	}
	if(sx*2%n||sy*2%n)
	{
		puts("nO");
		return 0;
	}
	sx=sx*2/n,sy=sy*2/n;
	for(int i=1;i<=n;i++)
	{
		if(!mp[{a[i].first+sx-a[i].first*2,sy-a[i].second}])
		{
			puts("No");
			return 0;
		}
	}
	puts("yEs");
	return 0;
}