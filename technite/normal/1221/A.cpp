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
		int n,c=0;
		cin>>n;
		for(int i =0; i<n;i++)
		{
			int t;
			cin>>t;
			if(t<=2048) c+=t;			
		}
		if(c>=2048) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
}