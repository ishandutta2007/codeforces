#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
int n,x,a,b;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>x>>a>>b;
		if(a>b)swap(a,b);
		int ans=b-a;
		ans+=min(a-1,x),x-=min(a-1,x);
		ans+=min(n-b,x),x-=min(n-b,x);
		cout<<ans<<endl; 
	}
}