#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main() 
{
	string n,s;
	int l,k;
	cin>>l>>k;
	cin>>n;
	int i,j;
	if(l==1&&k>0) cout<<'0';
	else
	{
	for(i=0,j=0;i<k&&j<l;j++)
	{
		if(j==0)
		{
			s.append("1");
			if(n[0]!='1')
			{
				
				i++;
				
			}
		}
		else
		{
			s.append("0");
			if(n[j]!='0')
			{
				
				i++;
				//cout<<i<<endl;
			}
		}
		//cout<<i<<j<<endl;;
	}
	for(int k=j;k<l;k++)
	{
		s.append(n.substr(k,1));
	}
	cout<<s;
}
}