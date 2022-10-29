#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int a[10],b[100005],now[100005];
set <pair <int,int> > s;
int main(int argc, char** argv) {
	for(int i=1;i<=6;i++)
		cin >> a[i];
	sort(a+1,a+7),reverse(a+1,a+7);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> b[i];
		s.insert({b[i]-a[1],i});
		now[i]=1;
	}
	int ans=2.1e9;
	while(1)
	{
		ans=min(ans,(*--s.end()).first-(*s.begin()).first);
		if(now[(*s.begin()).second]==6) break;
		int x=(*s.begin()).second;
		s.erase(s.begin());
		s.insert({b[x]-a[++now[x]],x});
	}
	cout << ans;
	return 0;
}