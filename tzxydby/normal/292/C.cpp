#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>res;
int n;
int us[10];
void add(vector<int>a)
{
	if(a.size()==4)
		res.push_back(a);
}
void go(const string &s,vector<int>a,int n)
{
	if(n==s.size())
	{
		add(a);
		return;
	}
	for(int i=1;i<=3&&n+i<=s.size();i++)
	{
		int now=0;
		for(int j=0;j<i;j++)
			now=now*10+s[n+j]-'0';
		if(s[n]=='0'&&i>1)
			break;
		if(now>255)
			break;
		a.push_back(now);
		go(s,a,n+i);
		a.pop_back();
	}
}
void calc(string s)
{
	if(s.size()<4)
		return;
	int nw[10];
	memset(nw,0,sizeof(nw));
	for(int j=0;j<s.size();j++)
		nw[s[j]-'0']++;
	for(int j=0;j<10;j++)
		if(us[j]&&nw[j]==0)
			return;
	vector<int>now;
	go(s,now,0);
}
void check(string s)
{
	if(s.size()<2)
		return;
	string w=s;
	reverse(w.begin(),w.end());
	calc(s+w);
	w=w.substr(1,(int)w.size()-1);
	calc(s+w);
}
void go(string s)
{
	check(s);
	if(s.size()==6)
		return;
	int n=s.size();
	s+='0';
	for(int i=0;i<10;i++)
	{
		if(us[i])
		{
			s[n]='0'+i;
			go(s);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		us[x]=1;
	}
	if(n<=6)
		go("");
	printf("%d\n",res.size());
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
		{
			printf("%d",res[i][j]);
			if(j<3)
				printf(".");
			else
				printf("\n");
		}
	}
	
	return 0;
}