#include <iostream>
using namespace std;
int a[100005],qzh[100005];
int main()
{
	int n;
	cin >> n;
	if(n>200)
	{
		cout << 1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		qzh[i]=qzh[i-1]^a[i];
	}
	int ans=1e9;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if((qzh[j]^qzh[i-1])>(qzh[k]^qzh[j]))
					ans=min(ans,j-i+(k-j-1));
			}
		}
	}
	if(ans>n) ans=-1;
	cout << ans;
	return 0;
}