#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
set <pair <int,int> > s;
pair <int,int> a[500005],b[500005];
int cnt;
int fa[500005];
inline int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].first,&a[i].second),fa[i]=i;
	sort(a+1,a+n+1);int C=0;
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		for(auto x:s)
		{
			if(x.first<=a[i].first) {b[++cnt]=x;continue;}
			if(x.first>=a[i].second) break;
			if(ff(x.second)==ff(i))
			{
				puts("NO");
				return 0;
			}
			fa[ff(x.second)]=ff(i);++C;
		}
		for(int i=1;i<=cnt;i++) s.erase(b[i]);
		s.insert({a[i].second,i});
	}
	if(C==n-1) puts("YES");
	else puts("NO");
	return 0;
}