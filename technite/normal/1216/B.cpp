#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int find(int A[],int x,int n)
{	
	int i=0;
	for(i=0;i<n;i++)
	{
		if(A[i]==x)
		{
			A[i]=0;
			break;
		}
	}
	return i;

}
int main() 
{
	int n;
	cin>>n;
	int A[n],B[n],C[n];
	for(int i=0;i<n;i++)
	{	
		cin>>A[i];
		B[i]=A[i];
		C[i]=A[i];
	}
	int sum=0;
	sort(A,A+n);
	string s;
	int j=0;
	for(int i=n-1;i>=0;i--)
	{
		int m=find(B,A[i],n);
		int t=m+1;
		string str= to_string(t);
		s.append(str);
		s.append(" ");
		sum+=A[i]*j;
		j++;
		//cout<<sum<<endl;
		
	}
	cout<<sum+n<<endl;
	cout<<s<<endl;
}