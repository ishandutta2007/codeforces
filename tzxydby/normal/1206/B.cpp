#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long a[N];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	long long ans=0,flag=0,k=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			ans++;
			flag=1;
		}
		else if(a[i]>0)
		{
			ans+=a[i]-1;
		}
		else
		{
			ans+=-a[i]-1;
			k++;
		}
	}
	if(k%2==1&&flag==0)
		ans+=2;
	cout<<ans<<endl;
	return 0;
}