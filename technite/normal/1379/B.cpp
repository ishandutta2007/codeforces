#include<bits/stdc++.h>
using namespace std;
string req="abacaba";
bool check(int x,string&s)
{
	for(int i=x;i<=x+6;i++)
	{
		if(s[i]==req[i-x]) continue;
		if(s[i]!='?') return 0;
		if(s[i]=='?') s[i]=req[i-x];
	}
	int cnt=0;
	for(int i=0;i<s.size();i++)
	{
		if(i<s.size()-6){
		if(s.substr(i,7)==req) cnt++;}
		if(s[i]=='?') s[i]='d';
	}
	return cnt==1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long l,r,m;
		cin>>l>>r>>m;
		bool flag=1;
		for(int a=l;a<=r;a++)
		{
			long long rem=(m+(r-l))%a;
			if(rem-2*(r-l)<=0)
			{
				cout<<a<<" ";
				long long b,c;
				if(rem>r-l)
				{
					int diff=rem-(r-l);
					c=r;
					b=r-diff;
				}
				else
				{
					b=r-rem;
					c=l;
				}
				cout<<c<<" "<<b<<'\n';
				flag=0;
			}
			if(!flag) break;
		}
	}
}