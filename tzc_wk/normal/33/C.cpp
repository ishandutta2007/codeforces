#include <bits/stdc++.h>
using namespace std;
long long n,Max,S,a[100100],sum,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for (int i=1;i<=n;i++)
		if (S+a[i]<0) S=0;
		else {S+=a[i];Max=max(Max,S);}
	Max=max(Max,S);
	ans=Max*2-sum;
	cout<<ans<<endl;
	return 0;
}