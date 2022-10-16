#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		string s,t;
		cin>>s>>t;
		int c=0;
		for (int i = 0; i<s.size(); i++)
		{
			for(int j=0;j<s.size();j++)
			{
				if(s[i]==t[j])
				{
					c=1;
					break;
				}
			}
			if(c==1) break;
		}
		if(c==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}