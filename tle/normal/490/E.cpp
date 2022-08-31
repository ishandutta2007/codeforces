#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n;
string s[233333],x[233333];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	string last="";
	for(int i=1;i<=n;i++)
	{
		string cp=s[i];
		if(last.length()>cp.length())
		{
			printf("NO\n");
			return 0;
		}
		if(last.length()<cp.length())
		{
			for(int g=0;g<cp.length();g++)
			{
				if(cp[g]=='?') cp[g]=(g==0)?'1':'0';
			}
			last=cp; x[i]=cp;
			continue;
		}
		int l=cp.length();
		string ans="";
		for(int p=0;p<l;p++)
		{
			string t=s[i];
			for(int s=0;s<p;s++) if(t[s]=='?') t[s]=last[s];
			if(t[p]=='?') t[p]=min((int)last[p]+1,(int)'9');
			for(int s=p+1;s<l;s++) if(t[s]=='?') t[s]='0';
			if(t<=last) continue;
			if(ans=="") ans=t;
			else ans=min(ans,t);
		}
		if(ans=="")
		{
			printf("NO\n");
			return 0;
		}
		x[i]=ans; last=ans;
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++) cout<<x[i]<<"\n";
}
//todo: make a spj with testlib