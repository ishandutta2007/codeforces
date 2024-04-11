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
		string s;
		int n;
		cin>>n;
		cin>>s;
		int p=s.find('1');
		int q=s.rfind('1');
		if(p==-1) cout<<n<<endl;
		else cout<<max(n-p,q+1)*2<<endl;

	}
}