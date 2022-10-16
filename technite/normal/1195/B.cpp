#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	long long int n,k;
	cin>>n>>k;
	
	long long int t=((2*n+3)-sqrt((2*n+3)*(2*n+3)-4*(n*n+n-2*k)))/2;
	cout<<t;
}