#include <iostream>
#define mod 1000000007
#define int long long
using namespace std;
inline int ksm(int x,int y)
{
	int rtn=1;
	while(y)
	{
		if(y&1)
			rtn*=x,rtn%=mod;
		x*=x,y>>=1,x%=mod;
	}
	return rtn;
}
int a[1005][1005];
signed main() {
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		for(int j=0;j<x;j++)
		{
			if(a[i][j]==2)
			{
				cout << 0;
				return 0;
			}
			a[i][j]=1;
		}
		if(a[i][x]==1)
		{
			cout << 0;
			return 0;
		}
		a[i][x]=2;
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin >> x;
		for(int j=0;j<x;j++)
		{
			if(a[j][i]==2)
			{
				cout << 0;
				return 0;
			}
			a[j][i]=1;
		}
		if(a[x][i]==1)
		{
			cout << 0;
			return 0;
		}
		a[x][i]=2;
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!a[i][j])
				++cnt;
		}
	}
	cout << ksm(2,cnt);
	return 0;
}