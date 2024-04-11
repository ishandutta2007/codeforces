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
		int A[n],B[n],f=0;
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>B[i];
			B[i]=B[i]-A[i];
			if(B[i]<0) f=f+2;
			if(B[i]>0&&B[i]!=B[i-1]) f++;

		}
		printf(f>1?"NO\n":"YES\n");

	}
}