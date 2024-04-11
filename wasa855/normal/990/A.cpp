#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long m,n,a,b;
	cin>>m>>n>>a>>b;
	long long add=m%n;
	long long ans=add*b;
	long long minn=n-add;
	ans=min(ans,minn*a);
	cout<<ans<<endl;
}