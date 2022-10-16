#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		for(int j=0;j<m;j++)
		{
			if(str[j]=='.')
			{
				if((i+j)&1)str[j]='B';
				else str[j]='W';
			}
		}
		cout<<str<<endl;
	}
}