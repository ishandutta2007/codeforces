#pragma GCC optimize("Ofast",3,"inline")
#include<bits/stdc++.h>
using namespace std;
int vis[7],sum[7];
string a[7],t[7];
vector<string>ans(10,"{"),now;
void solve()
{
	now.clear();
	for(int i=1;i<=6;i++)	
		sum[i]=(int)t[i].size();
	if(sum[2]<=sum[1]||sum[2]<=sum[3]||sum[5]<=sum[4]||sum[5]<=sum[6])
		return;
	if(t[1][0]!=t[4][0]||t[1][t[1].size()-1]!=t[5][0]||t[2][0]!=t[4][t[4].size()-1])
		return;
	if(t[2][t[2].size()-1]!=t[6][0]||t[5][t[5].size()-1]!=t[3][0]||t[3][t[3].size()-1]!=t[6][t[6].size()-1])
		return;
	if(sum[1]+sum[3]-1!=sum[2]||sum[4]+sum[6]-1!=sum[5])
		return;
	if(t[2][sum[1]-1]!=t[5][sum[4]-1])
		return;
	string s="";
	s+=t[1];
	for(int i=1;i<=sum[2]-sum[1];i++)
		s+='.';
	now.push_back(s);
	for(int i=2;i<sum[4];i++)
	{
		s="";
		s+=t[4][i-1];
		for(int j=2;j<sum[1];j++)
			s+='.';
		s+=t[5][i-1];
		for(int j=1;j<=sum[2]-sum[1];j++)
			s+='.';
		now.push_back(s);
	}
	now.push_back(t[2]);
	for(int i=sum[4]+1;i<sum[5];i++)
	{
		s="";
		for(int j=1;j<=sum[2]-sum[3];j++)
			s+='.';
		s+=t[5][i-1];
		for(int j=2;j<sum[3];j++)
			s+='.';
		s+=t[6][i-sum[4]];
		now.push_back(s);
	}
	s="";
	for(int i=1;i<=sum[2]-sum[3];i++)
		s+=".";
	s+=t[3];
	now.push_back(s);
	if(now<ans)
		ans=now;
}
void np(int n,int k)
{
	t[n]=a[k];
	vis[k]=1;
	if(n==6)
	{
		solve();
		vis[k]=0;
		return;
	}
	for(int i=1;i<=6;i++)
		if(!vis[i])
			np(n+1,i);
	vis[k]=0;
}
int main()
{
	ios::sync_with_stdio(false);
	for(int i=1;i<=6;i++)
		cin>>a[i];
	np(0,0);
	if(ans[0]=="{")
		cout<<"Impossible"<<endl;
	else 
		for(int i=0;i<(int)ans.size();i++)
			cout<<ans[i]<<endl;
	return 0;
}