#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int p[100005],a[105][105];
inline bool qwq(int a,int b)
{
	return max(a,b)-min(a,b)==1;
}
inline void solve(int n)
{
	if(n==2)
	{
		cout << -1 << "\n";
		return ;
	}
	for(int i=1;i<=n*n;i++)
	{
		p[i]=i;
	}
	while(1)
	{
		random_shuffle(p+1,p+n*n+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=p[(i-1)*n+j];
		int flag=1;
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(qwq(a[i][j],a[i+1][j])) flag=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<n;j++)
			{
				if(qwq(a[i][j],a[i][j+1])) flag=0;
			}
		}
		if(flag) break;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
}
signed main(int argc, char** argv) {
	int T;
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		solve(n);
	}
	return 0;
}