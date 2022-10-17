#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
typedef vector<int>vi;
int n;
vector<vi>z;
vector<pair<vi,vi>>zz;
void gao(vi&a)
{
	if(a.size()<6)
	{
		z.push_back(a);
		a.clear();
	}
	else
	{
		vi c;
		for(int i=0;i<4;i++)
			c.push_back(a.back()),a.pop_back();
		reverse(c.begin(),c.end());
		c.push_back(a.back());
		z.push_back(c);
	}
}
int main()
{
	cin>>n;
	vi a(n),v(n),c;
	vector<vi>b,d2,d3;
	for(auto&i:a)
		cin>>i,i--;
	for(int i=0;i<n;i++)
		if(!v[i])
		{
			c.clear();
			do
			{
				v[i]=1;
				c.push_back(i);
				i=a[i];
			}
			while(!v[i]);
			b.push_back(c);
		}
	for(auto&i:b)
		while(i.size()>3)
			gao(i);
	for(auto&i:b)
		if(i.size()==2)
			d2.push_back(i);
		else if(i.size()==3)
			d3.push_back(i);
	while(d2.size()&&d3.size())
	{
		zz.push_back(make_pair(d2.back(),d3.back()));
		d2.pop_back(),d3.pop_back();
	}
	while(d2.size()>1)
	{
		vi o=d2.back();
		d2.pop_back();
		zz.push_back(make_pair(d2.back(),o));
		d2.pop_back();
	}
	while(d3.size()>2)
	{
		vi o=d3.back(),u;
		d3.pop_back();
		vi p=d3.back();
		d3.pop_back();
		vi q=d3.back();
		d3.pop_back();
		u.push_back(o[0]);
		u.push_back(o[1]);
		zz.push_back(make_pair(p,u));
		u.pop_back();
		u.push_back(o[2]);
		zz.push_back(make_pair(q,u));
	}
	while(d2.size())
		z.push_back(d2.back()),d2.pop_back();
	while(d3.size())
		z.push_back(d3.back()),d3.pop_back();
	cout<<z.size()+zz.size()<<endl;
	for(auto&i:z)
	{
		cout<<i.size()<<endl;
		for(auto&j:i)
			cout<<j+1<<' ';
		cout<<endl;
		for(int j=1;j<i.size();j++)
			cout<<i[j]+1<<' ';
		cout<<i[0]+1<<endl;
	}
	for(auto&i:zz)
	{
		cout<<i.X.size()+i.Y.size()<<endl;
		for(auto&j:i.X)
			cout<<j+1<<' ';
		for(auto&j:i.Y)
			cout<<j+1<<' ';
		cout<<endl;
		for(int j=1;j<i.X.size();j++)
			cout<<i.X[j]+1<<' ';
		cout<<i.X[0]+1<<' ';
		for(int j=1;j<i.Y.size();j++)
			cout<<i.Y[j]+1<<' ';
		cout<<i.Y[0]+1<<endl;
	}
	return 0;
}