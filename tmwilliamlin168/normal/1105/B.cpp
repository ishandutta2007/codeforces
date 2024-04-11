#include<bits/stdc++.h>
using namespace std;
int f[26]={0};
int main()
{
	int n,k;
	string s;
	cin>>n>>k;
	cin>>s;
	int t=1;
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i-1])
			t++;
		else
		{
			f[s[i-1]-'a']+=t/k;
			t=1;
		}
	}
	f[s[n-1]-'a']+=t/k;
	int mx=0;
	for(int i=0;i<26;i++)
	{
		mx=max(mx,f[i]);
		//cout<<f[i]<<endl;
	}
	cout<<mx<<endl;
}