#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
#define pb push_back
int min(int a, int b){ return a>b?b:a;}
int min(int a, int b, int c){ return min(a,min(b,c));}
int max(int a, int b){ return a>b?a:b;}
int max(int a, int b, int c){ return max(a,max(b,c));}
int mid(int a, int b, int c){ return min(max(a,b),max(a,c),max(b,c));}
multiset<int> Set;
multiset<int>::iterator it;
int main()
{
	int x,y,z,a,b,c,n,i;
	scanf("%i",&n);
	scanf("%i %i %i",&x,&y,&z);
	a=min(x,y,z);
	b=mid(x,y,z);
	c=max(x,y,z);
	bool ok=1;
	int sol=0;
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		if(x>a+b+c) ok=0;
		if(x>b+c) sol++;
		else Set.insert(x);
	}
	if(!ok) return printf("-1\n"),0;
	//while(Set.size() && *Set.rbegin()>b+c) sol++,Set.erase(--Set.end());
	while(Set.size() && *Set.rbegin()>a+c)
	{
		sol++;
		Set.erase(--Set.end());
		if(Set.size())
		{
			it=Set.upper_bound(a);
			if(it!=Set.begin()) Set.erase(--it);
		}
	}
	while(Set.size() && *Set.rbegin()>max(a+b,c))
	{
		sol++;
		Set.erase(--Set.end());
		if(Set.size())
		{
			it=Set.upper_bound(b);
			if(it!=Set.begin()) Set.erase(--it);
		}
	}
	if(a+b>c)
	{
		while(Set.size() && *Set.rbegin()>c)
		{
			sol++;
			Set.erase(--Set.end());
			if(Set.size())
			{
				it=Set.upper_bound(c);
				if(it!=Set.begin()) Set.erase(--it);
			}
		}
	}
	vector<int> del;
	while(Set.size())
	{
		sol++;
		//if(sol>n) return printf("1??? %i\n",*Set.begin()),0;
		//int cnt=0;
		del.clear();
		it=Set.upper_bound(c);
		if(it!=Set.begin()) it--,del.pb(*it),Set.erase(it);//,cnt++;
		if(Set.size())
		{
			it=Set.upper_bound(b);
			if(it!=Set.begin()) it--,del.pb(*it),Set.erase(it);//,cnt++;
		}
		if(Set.size())
		{
			it=Set.upper_bound(a);
			if(it!=Set.begin()) it--,del.pb(*it),Set.erase(it);//,cnt++;
		}
		if(del.size()!=3)
		{
			sol--;
			for(i=0;i<del.size();i++) Set.insert(del[i]);
			break;
		}
	}
	while(Set.size())
	{
		sol++;
		if(sol>n) return printf("2??? %i %i\n",*Set.begin(),Set.size()),0;
		it=Set.upper_bound(c);
		if(it!=Set.begin()) Set.erase(--it);
		if(Set.size())
		{
			it=Set.upper_bound(a+b);
			if(it!=Set.begin()) Set.erase(--it);
		}
	}
	printf("%i\n",sol);
	return 0;
}