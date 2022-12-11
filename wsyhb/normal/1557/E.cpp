#include<bits/stdc++.h>
using namespace std;
int curY,cnt;
inline string move(int x,int y)
{
	assert(++cnt<=130);
	cout<<x<<" "<<y<<endl;
	curY=y;
	string s;
	cin>>s;
	return s;
}
inline bool scan_row(int row)
{
	vector<int> pos;
	for(int i=1;i<=8;++i)
	{
		if(i!=curY)
			pos.push_back(i);
	}
	assert((int)pos.size()==7);
	for(int i=0;i<7;++i)
	{
		int y=pos[i];
		string s=move(row,y);
		if(s=="Done")
			return true;
		if(s[0]=='U'&&s[1]=='p')
			return scan_row(row);
		if((int)s.size()>=4&&s[0]=='D'&&s[1]=='o'&&s[2]=='w'&&s[3]=='n')
			return false;
	}
	return false;
}
inline bool solve()
{
	curY=1,cnt=0;
	for(int row=1;row<=8;++row)
	{
		string s=move(row,curY);
		if(s=="Done")
			return true;
		if(row>1&&(int)s.size()>=4&&s[0]=='D'&&s[1]=='o'&&s[2]=='w'&&s[3]=='n')
			continue;
		if(scan_row(row))
			return true;
	}
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		bool flag=solve();
		assert(flag);
	}
	return 0;
}