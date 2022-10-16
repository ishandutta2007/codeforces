#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int l;
		cin>>l;
		string s,t;
		cin>>s>>t;
		int count=0;
		int A[l]={0};
		for(int i=0;i<l;i++)
		{	
			if(s[i]==t[i]) count++;
			else A[i]=1;
		}
		int B[2],i,j;
		if(count<l-2||count==l-1) cout<<"No"<<endl;
		else if(count==l) cout<<"Yes"<<endl;
		else
		{
			for(i=0,j=0;i<l,j<2;i++){
				if(A[i]==1)
				{
					B[j]=i;
					j++;
				}
			}
			if(s[B[0]]==s[B[1]]&&t[B[0]]==t[B[1]]) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;	

					
		}	
	}
}