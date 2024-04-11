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
		int n;
		cin>>n;
		int A[n];
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}	
		for(int i=0;i<n;i++)
		{
			int count=1,k,j=A[i];
			while(j!=i+1)
			{
				int t=j-1;
				j=A[t];
				count++;
			}
			cout<<count<<" ";
		}
		cout<<endl;
	}
}