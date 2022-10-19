#include<bits/stdc++.h>
using namespace std;
const int N=200005;
string s,t,a,b;
int main()
{
	ios::sync_with_stdio(false);
	int n,m,flag=0;
	cin>>n>>m>>s>>t;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='*')
		{
			if(n-1>m)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			a=s.substr(0,i);
			b=t.substr(0,i);
			if(a!=b)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			a=s.substr(i+1,n-i);
			b=t.substr(m-n+i+1,n-i);
			if(a!=b)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		if(s!=t)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}