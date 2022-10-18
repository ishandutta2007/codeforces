#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
signed main()
{
	int n,m,k;
	cin>>n>>m>>k;
	if(n+k<m)
	{
		cout<<"-\n";
		return 0;
	}
	if(m+k<n)
	{
		cout<<"+\n";
		return 0;
	}
	if(k==0&&n==m)
	{
		cout<<"0\n";
		return 0;
	}
	cout<<"?\n";
	return 0;
}
//safcahdsifa