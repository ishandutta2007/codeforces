#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int mid=(s.size()-1)/2;
	cout<<s[mid];
	for(int i=1;i<=mid;i++)
		cout<<s[mid+i]<<s[mid-i];
	if(s.size()%2==0)
	cout<<s[s.size()-1];
	cout<<endl;	
	return 0;
}