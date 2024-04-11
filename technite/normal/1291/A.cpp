#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long l;
		cin>>l;
		string s,f="";
		cin>>s;
		long long count=0;
		for(int i=0;i<s.size();i++)
		{
			if((s[i]-'0')%2)
			{
				f+=s.substr(i,1);
				count++;
			}
			if(count>1)
			{
				break;
			}
		}
		if(f.size()>1) cout<<f<<endl;
		else cout<<-1<<endl;
	}
}