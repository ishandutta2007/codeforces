#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,x;
	cin>>n;
	while(n--)
	{
		cin>>x;
		if(x%2==0) x--;
		cout<<x<<" ";
	}
	return 0;
}