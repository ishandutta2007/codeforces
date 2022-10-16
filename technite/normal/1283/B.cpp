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
		long long int n,k;
		cin>>n>>k;
		long long int i=n/k;
		
		
		long long int m=min(n-i*k,k/2);
		cout<<i*k+m<<endl;
		
	}
}