#include<bits/stdc++.h>
using namespace std;
 int main()
 {
 	long long t;
 	cin>>t;
 	while(t--)
 	{
 		long long n,k,sum=0,t,f=0;
 		cin>>n>>k;
 		for(long long i=1;i<n;i++)
 		{
 			sum+=i;
 			if(sum==k)
 			{	
 				f=1;
 				t=i;
 				break;
 			}
 			else if(sum>k)
 			{
 				t=i;
 				break;
 			}
 			
 		}
 		if(f==0)
 		{
 			for(int i=1;i<n-t;i++)
 			{
 				cout<<'a';
 			}
 			cout<<'b';
 			for (int i = 0; i <t; ++i)
 			{
 				if(i!=sum-k) cout<<'a';
 				else cout<<'b';
 			}
 		}
 		else
 		{
 			for(int i=1;i<n-t;i++){
 				cout<<'a';
 			}
 			cout<<"bb";
 			for(int i=0;i<t-1;i++)
 			{
 				cout<<'a';
 			}
 		}
 		cout<<endl;


 	}
 }