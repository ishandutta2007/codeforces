#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,x,y,s1=0,s2=0;
	cin>>n;
	while(n--)
	{
		cin>>x>>y;
		if(x!=y)
		{
			if(x>y) s1++;
			else s2++;
		}
	}
	cout<<(s1==s2?"Friendship is magic!^^":(s1>s2?"Mishka":"Chris"));	
	return 0;
}