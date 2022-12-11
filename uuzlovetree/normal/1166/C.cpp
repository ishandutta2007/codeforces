#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]=abs(a[i]);
	sort(a+1,a+n+1);
	int r=0;
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		while(r+1<=n&&a[r+1]<=a[i]*2)r++;
		ans+=1ll*(r-i);
	}
	cout<<ans<<endl;
}