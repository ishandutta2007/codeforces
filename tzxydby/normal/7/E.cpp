#include<bits/stdc++.h>
using namespace std;
string s,t;
map<string,int>mp;
int solve(int l,int r)
{
	int sum;
	sum=0;
	for(int i=r;i>=l;i--)
	{
		if(s[i]==')')
			sum++;
		if(s[i]=='(')
			sum--;
		if(!sum&&(s[i]=='+'||s[i]=='-'))
		{
			int sl=solve(l,i-1),sr=solve(i+1,r);
			return sl&&sr&&(s[i]!='-'||sr>1);	
		}
	}
	sum=0;
	for(int i=r;i>=l;i--)
	{
		if(s[i]==')')
			sum++;
		if(s[i]=='(')
			sum--;
		if(!sum&&(s[i]=='*'||s[i]=='/'))
		{
			int sl=solve(l,i-1),sr=solve(i+1,r);
			return sl>1&&sr>1&&(s[i]!='/'||sr>2)?2:0;
		}
	}
	if(s[l]=='(')
		return solve(l+1,r-1)?3:0;
	string a=s.substr(l,r-l+1);
	return mp.count(a)?mp[a]:3;
}
int init()
{
	getline(cin,s);
	int len=0;
	for(int i=0;s[i]!='\0';i++)
		if(s[i]!=' ')
			s[len++]=s[i];
	return solve(0,len-1);
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(t[t.length()-1]=='#')
			cin>>t;
		cin>>t;
		mp[t]=init();
	}
	cout<<(init()?"OK":"Suspicious")<<endl;
	return 0;
}