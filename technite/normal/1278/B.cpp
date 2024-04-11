#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a,b;
		cin>>a;
		cin>>b;
		int x;
		if(a>=b) x=a-b;
		else x=b-a;
		int i=sqrt(x);
		
		
		while(i>=0)
		{
			if(x>i*(i+1)/2) i++;
			else
			{
				if((i*(i+1)/2)%2==x%2)
				{
					cout<<i<<endl;
					break;
				}
				else i++;
			}
		}
	
	}
}