#include <bits/stdc++.h>
using namespace std;
int n,ans=1;
string s;
int main()
{
	cin>>n;
	cin>>s;
	for (int i=1;i<s.size();i++)
		if (s[i-1]!=s[i])
			ans++;
	cout<<min(ans+2,n);
}