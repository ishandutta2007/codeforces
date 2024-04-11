#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,l,r;
	cin>>n>>l>>r;
	long long minv=0,maxv=0,cnt;
	for(int i=1;i<=r;i++)
	{
		cnt=pow(2,i-1);
		maxv+=cnt;
	}
	for(int i=r+1;i<=n;i++)
	{
		maxv+=cnt;
	}
	for(int i=1;i<=l;i++)
	{
		cnt=pow(2,i-1);
		minv+=cnt;
	}
	for(int i=l+1;i<=n;i++)
	{
		minv++;
	}
	cout<<minv<<" "<<maxv<<endl;
	return 0;
}