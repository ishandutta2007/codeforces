#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
string s[500007];
string now,last;
int main()
{
	cin >> n;ans=0;
	for (int i=1;i<=n;i++)
	{
		char ch=getchar(),ch1=getchar();
		cin >> s[i] ;
	}
	for (int i=n-1;i>=1;i--)
	{
		now="";int r=0;last="";
		while (now<=s[i+1] && r<=s[i].length())
		{
			last=now;
			now+=s[i][r];++r;
		}
		ans+=s[i].length()-r;s[i]=last;
	}
	for (int i=1;i<=n;i++)
	{
		cout<<"#";
		cout<<s[i]<<endl;
	}
	return 0;
}