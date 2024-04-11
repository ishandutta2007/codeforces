#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long d;
		cin>>d;
		string s,s1="",s2="";
		cin>>s;
		int t=1,f=0;
		for(int i=0;i<d;i++)
		{
			if(s[i]=='1') t=0;
			if(t==1)
			{
			if(s[i]=='2')
			{
				s1+='1';
				s2+='1';
			}
			else
			{
				s1+='0';
				s2+='0';
			}
		}
		else
		{
			if(f==0){
			s1+='1';
			f=1;
			s2+='0';
			}
			else
			{
				s2+=s[i];
				s1+='0';
			}
		}
		}
		cout<<s1<<endl;
		cout<<s2<<endl;

	}
}