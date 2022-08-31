#include <algorithm>
#include <utility>
#include <iostream>
#define N 100005
using namespace std;
pair< pair<int, int>, int> tab[N];
int t[N][3];
int main()
{
	ios_base::sync_with_stdio(0);
	int n, m, k;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)
	{
		for(int j=0; j<3; j++)
		{
			cin>>t[i][j];
		}
	}
	long long int sum=0;
	for(int i=1; i<=k; i++)
	{
		int a;
		cin>>a;
		for(int i=1; i<=m; i++)
		{
			if(a>=t[i][0] && a<=t[i][1])
			{
				sum+=(a-t[i][0]+t[i][2]);
			}
		}
	}
	cout<<sum<<endl;
	//system("pause");
	return 0;
}