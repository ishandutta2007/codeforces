#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#define X first
#define Y second
using namespace std;
map<int,vector<int>>a;
map<int,int>c;
multiset<int>s;
int n,h,x,y,z;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	s.insert(0);
	for(int i=0;i<n;i++)
	{
		cin>>h>>x>>y;
		a[x].push_back(h);
		a[y].push_back(-h);
	}
	for(auto i:a)
	{
		for(auto j:i.Y)
			if(j>0)
				s.insert(j);
			else
				s.erase(s.find(-j));
		c[i.X]=*s.rbegin();
	}
	h=0;
	for(auto i:c)
		if(h!=i.Y)
			z+=2,h=i.Y;
	cout<<z<<endl;
	for(auto i:c)
		if(h!=i.Y)
			printf("%d %d\n%d %d\n",i.X,h,i.X,i.Y),h=i.Y;
}