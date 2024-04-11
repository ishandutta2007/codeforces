#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int ans=(s.size()-1)/2;
	int flag=0;
	for(int i=1;i<s.size();i++)
		if(s[i]!='0')
			flag=1;
	if(!flag)
		cout<<s.size()/2;
	else
		cout<<ans+flag<<endl;
	return 0;
}