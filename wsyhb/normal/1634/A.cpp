#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		string t=s;
		reverse(t.begin(),t.end());
		puts(k==0||s+t==t+s?"1":"2");
	}	
	return 0;
}