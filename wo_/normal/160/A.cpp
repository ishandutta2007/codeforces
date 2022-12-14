#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> coins;
	scanf("%d",&n);
	int total=0;
	for(int i=0;i<n;i++)
	{
		int in;
		scanf("%d",&in);
		total+=in;
		coins.push_back(in);
	}
	sort(coins.begin(),coins.end());
	int cnt=0;
	int take=total/2+1;
	int sum=0;
	for(int i=n-1;i>=0;i--)
	{
		cnt++;
		sum+=coins[i];
		if(sum>=take) break;
	}
	printf("%d\n",cnt);
	return 0;
}