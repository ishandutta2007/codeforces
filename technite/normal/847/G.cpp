#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int maxima(int A[],int x){
	int i,c;
	c=A[0];
	for(i=0;i<x;i++){
		if (A[i]>c){
			c=A[i];
		}
	}
	return c;
}
int main()
{
	string s;
	int n;
	scanf("%d",&n);
	int A[7];
	for(int i=0;i<n;i++)
	{
		string c;
		cin>>c;
		s.append(c);
	}

	for(int j=0;j<7;j++)
	{
		int count=0;
		for(int i=j;i<7*n;i=i+7)
		{
			int r= s[i] -'0';
			count=count+r;		
		}
		A[j]=count;

	}
	int f=maxima(A,7);
	cout<<f;
	
 	return 0;
}