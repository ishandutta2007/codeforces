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
		int h,m;
		cin>>h>>m;
		int h1=(24-h)*60;
		cout<<h1-m<<endl;
	}
}