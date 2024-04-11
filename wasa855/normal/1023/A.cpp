#include<bits/stdc++.h>
using namespace std;
char a[200005];
char b[200005];
int main()
{
	int m,n;
	cin>>n>>m;
	scanf("\n%s\n%s",a+1,b+1);
	bool have=false;
	if(strcmp(a+1,b+1)==0)
	{
		cout<<"YES\n";
		return 0;
	}
	if(n>m+1)
	{
		cout<<"NO\n";
		return 0;
	}
	int k=n;
	int l=1;
	for(l=1;l<=k;l++)
	{
		if(a[l]=='*')
		{
			have=true;
			break;
		}
		if(a[l]!=b[l])
		{
			l--;
			break;
		}
	}
	if(l==k+1)
	{
		l--;
	}
	int r=1;
	for(r=1;r<=k;r++)
	{
//		cout<<a[n-r+1]<<"\n";
		if(a[n-r+1]=='*')
		{
			have=true;
			break;
		}
		if(a[n-r+1]!=b[m-r+1])
		{
			r--;
			break;
		}
	}
	if(have==false)
	{
		cout<<"NO\n";
		return 0;
	}
	if(r==k+1)
	{
		r--;
	}
//	cout<<l<<" "<<r<<"\n";
	if(l+r-1==n)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	return 0;
}