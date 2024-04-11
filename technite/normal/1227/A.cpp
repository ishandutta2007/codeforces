#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int minima(int A[],int x){
	long int i,c;
	c=A[0];
	for(i=0;i<x;i++){
		if (A[i]<c){
			c=A[i];
		}
	}
	return c;
}
int maxima(int A[],int x){
	long int i,c;
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
	int n;
	cin>>n;
	while(n--)
	{
		int t;
		cin>>t;
		int A[t],B[t];
		for(int i=0;i<t;i++)
		{
			cin>>A[i]>>B[i];
		}
		cout<<max(maxima(A,t)-minima(B,t),0)<<endl;
	}
}