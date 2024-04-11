#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=3050;
int h[N][N],mn1[N][N],mn2[N][N];
int main()
{
	int n,m,a,b,last,x,y,z;
	scanf("%i %i %i %i",&n,&m,&a,&b);
	scanf("%i %i %i %i",&last,&x,&y,&z);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		h[i][j]=last;
		last=((ll)last*x+y)%z;
	}
	for(int i=1;i<=n;i++)
	{
		deque<int> dq;
		auto push=[&](int x)
		{
			while(dq.size() && h[i][dq.back()]>=h[i][x]) dq.pop_back();
			dq.push_back(x);
		};
		for(int j=1;j<b;j++) push(j);
		for(int j=1;j<=m-b+1;j++)
		{
			push(j+b-1);
			while(dq.front()<j) dq.pop_front();
			mn1[i][j]=h[i][dq.front()];
		}
	}
	for(int j=1;j<=m-b+1;j++)
	{
		deque<int> dq;
		auto push=[&](int x)
		{
			while(dq.size() && mn1[dq.back()][j]>=mn1[x][j]) dq.pop_back();
			dq.push_back(x);
		};
		for(int i=1;i<a;i++) push(i);
		for(int i=1;i<=n-a+1;i++)
		{
			push(i+a-1);
			while(dq.front()<i) dq.pop_front();
			mn2[i][j]=mn1[dq.front()][j];
		}
	}
	ll ans=0;
	for(int i=1;i<=n-a+1;i++) for(int j=1;j<=m-b+1;j++) ans+=mn2[i][j];
	printf("%lld\n",ans);
	return 0;
}