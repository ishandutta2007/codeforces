#include <bits/stdc++.h>
#include <map>
using namespace std;
map<string,int> name;
int n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		name[s]++;
		if(name[s]==1)
		{
			cout<<"OK"<<endl;
		}
		else
		{
			cout<<s<<name[s]-1<<endl;
		}
	}
	return 0;
}