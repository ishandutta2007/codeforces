#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;
int a[300005],c[300005];
vector <int> v[300005];
int cnt=0;
unordered_map <int,int> mp;
signed main(int argc, char** argv) {
	int n,x=0;
	long long ans=0;
	cin >> n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	cnt=1;
	for(int i=1;i<=n;i++)
		v[1].push_back(a[i]);
	for(int i=30;i>=0;i--)
	{
		long long ling=0,yi=0;
	//	cout << i << "\n";
		for(int j=1;j<=cnt;j++)
		{
			int qwq0=0,qwq1=0;
			for(auto t:v[j])
			{
				if((t&(1<<i))) ++qwq1,yi+=qwq0;
				else ++qwq0,ling+=qwq1;
			}
		}
		if(ling<=yi)
			ans+=ling;
		else x|=(1<<i),ans+=yi;
		for(int j=1;j<=cnt;j++) v[j].clear();
		mp.clear();
		for(int j=1;j<=n;j++)
		{
			c[j]|=(a[j]&(1<<i));
			a[j]%=(1<<i);
		}
		cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(!mp[c[j]]) mp[c[j]]=++cnt;
			v[mp[c[j]]].push_back(a[j]);
		}
	}
	cout << ans << " " << x;
	return 0;
}