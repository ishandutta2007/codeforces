#include<bits/stdc++.h>
using namespace std;
int n;
inline int query(string s)
{
	cout<<s<<endl;
	int k;
	scanf("%d",&k);
	if(k==-1||k==n)
		exit(0);
	return k;
}
int main()
{
	scanf("%d",&n);
	int c0=query(string(n,'F'));
	string ans(n,'F');
	queue<int> q;
	for(int i=1;i<=n/3;++i)
	{
		int delta=query(string(2*(i-1),'F')+"TT"+string(n-2*i,'F'))-c0;
		if(delta==2)
			ans[2*i-2]=ans[2*i-1]='T';
		else if(!delta)
			q.push(2*i-2);
	}
	string s;
	for(int i=0;i<n;++i)
		s+=i&1?'F':'T';
	int c1=query(s);
	for(int i=n/3*2;i<n;++i)
	{
		if(!q.empty())
		{
			int pos=q.front();
			q.pop();
			string t=s;
			t[pos]='F',t[pos+1]='T';
			t[i]=s[i]^'F'^'T';
			int delta=query(t)-c1;
			if(delta>0)
				ans[pos+1]='T';
			else
				ans[pos]='T';
			if(delta==3||delta==-1)
				ans[i]=t[i];
			else
				ans[i]=s[i];
		}
		else
		{
			int delta=query(string(i,'F')+'T'+string(n-i-1,'F'))-c0;
			if(delta==1)
				ans[i]='T';
		}
	}
	query(ans);
	return 0;
}