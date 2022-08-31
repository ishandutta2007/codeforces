#include <iostream>
#define N 505
#define uint long long int
using namespace std;
uint d[N][N];
uint kol[N];
uint odp[N];
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin>>d[i][j];
		}
	}
	for(int i=1; i<=n; i++)
	{
		cin>>kol[n-i+1];
	}
	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				d[i][j]=min(d[i][j], d[i][kol[k]]+d[kol[k]][j]);
			}
		}
		for(int i=1; i<=k; i++)
		{
			for(int j=1; j<=k; j++)
			{
				odp[k]+=d[kol[i]][kol[j]];
			}
		}
	}
	for(int i=n; i>=1; i--)
	{
		cout<<odp[i]<<" ";
	}
	cout<<endl;
	return 0;
}