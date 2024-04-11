#include<bits/stdc++.h>
using namespace std;
const int N=55;
int score[11]={0,25,18,15,12,10,8,6,4,2,1},win[N][N],point[N],cnt;
map<string,int>mp;
int get_id(string str)
{
	if(mp.find(str)==mp.end())
		return mp[str]=++cnt;
	return mp[str];
}
int cmp1(string s1,string s2)
{
	int a=get_id(s1),b=get_id(s2);
	if(point[a]!=point[b])
		return point[a]>point[b];
	for(int i=1;i<=50;i++)
		if(win[a][i]!=win[b][i])
			return win[a][i]>win[b][i];
}
int cmp2(string s1,string s2)
{
	int a=get_id(s1),b=get_id(s2);
	if(win[a][1]!=win[b][1])
		return win[a][1]>win[b][1];
	else
		return cmp1(s1,s2);
}
int main()
{
	int n,t;
	string str; 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		for(int j=1;j<=t;j++)
		{
			cin>>str;
			int id=get_id(str);
			if(j<=10)
				point[id]+=score[j];
			win[id][j]++; 
		} 
	}
	string w1=mp.begin()->first,w2=mp.begin()->first;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		if(cmp1(it->first,w1))
			w1=it->first;
		if(cmp2(it->first,w2))
			w2=it->first;
	}
	cout<<w1<<endl<<w2<<endl;
	return 0;
}