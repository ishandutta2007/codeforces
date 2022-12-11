#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,h,x,ans=0;
	cin>>n>>h;
	while(n--)
	{
		cin>>x;
		ans+=(x>h?2:1);
	}
	cout<<ans;
	return 0;
}