#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int k;
	cin>>k;
	string s;
	for(int i=1;i<3000;i++)
	{
		string t = to_string(i);
		s.append(t);
	}
	cout<<s[k-1];
}