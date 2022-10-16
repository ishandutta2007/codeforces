#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,k;
	cin>>n>>m>>k;
	cout<<m+n+m*n-3<<endl;
	string s1="",s2="";
	for(int i=0;i<m-1;i++)
	{
		cout<<'L';
		s1+='L';
		s2+='R';
	}
	for(int i=0;i<n-1;i++)
	{
		cout<<'U';
	}
	for(int i=0;i<n;i++)
	{
		if(i%2)
		{
			cout<<s1;
		}
		else cout<<s2;
		if(i!=n-1)
		cout<<'D';
		
	}
}