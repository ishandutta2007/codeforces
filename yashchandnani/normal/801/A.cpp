#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	string s1="VK";
	string s2="KK";
	string s3="VV";
	int ans=0,flag=0;
	size_t pos=-1;
	while((pos=s.find(s1,pos+1))!=string::npos){

		ans++;

	}
	pos=-1;
	while ((pos=s.find(s2,pos+1))!=string::npos)
	{

		if ((pos==0)||(s[pos-1]!='V'))
		{
			flag++;
		}
		if (flag)
		{
			break;
		}
	}
	pos=-1;
	while ((pos=s.find(s3,pos+1))!=string::npos)
	{
		if (flag)
		{
			break;
		}
		if ((pos==s.size()-1)||(s[pos+2]!='K'))
		{
			flag++;
		}
	}
	if (flag)
	{
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}