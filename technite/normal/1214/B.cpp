#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	int b,g,n;
	cin>>b>>g>>n;
	cout<<n+1-max(n-b,0)-max(n-g,0);
}