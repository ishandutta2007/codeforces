#include<bits/stdc++.h>
using namespace std;
char a[55];
int main()
{
	int n,m;
	cin>>n>>m;
	cin>>a;
	sort(a,a+n);
	int lst='a'-10;
	int ans=0;
	int sum=0;
	for(int i=0;i<=n;i++)
	{
		if(a[i]-lst>1)
		{
			ans+=a[i]-'a'+1;
			lst=a[i];
			sum++;
		}
		if(sum==m)
		{
			cout<<ans<<endl;
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}