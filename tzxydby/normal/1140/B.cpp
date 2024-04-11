#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		cin>>n>>s;
		int last1=0,ans1=0;
		for(int i=0;i<n;i++)
			if(s[i]=='<')
				last1=i;
		for(int i=last1;i<n;i++)
			ans1+=(s[i]=='>');
		int last2=n-1,ans2=0;
		for(int i=n-1;i>=0;i--)
			if(s[i]=='>')
				last2=i;
		for(int i=last2;i>=0;i--)
			ans2+=(s[i]=='<');
		cout<<min(ans1,ans2)<<endl;
	}
	return 0;
}