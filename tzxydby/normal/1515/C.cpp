#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,x,a[N],d[N],h[N];
set<pair<int,int>>s;
void sol()
{
	scanf("%d%d%d",&n,&m,&x);
	s.clear();
	for(int i=1;i<=m;i++)
		s.insert(make_pair(0,i)),h[i]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int p=s.begin()->second;
		s.erase(s.begin());
		d[i]=p;
		h[p]+=a[i];
		s.insert(make_pair(h[p],p));
	}
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%d ",d[i]);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}