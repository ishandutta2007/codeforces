#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i-1]*a[i]==6)
		{
			cout<<"Infinite\n";
			return 0;
		}
		if(a[i-1]*a[i]==2) ans+=3;
		if(a[i-1]*a[i]==3) ans+=4;
		if(a[i-2]==3&&a[i]==2) ans--;
	}
	cout<<"Finite\n";
	cout<<ans<<endl;
	return 0;
}

///ascjks