#include <bits/stdc++.h>
#include <map>
#include <set>
#include <istream>
#include <cstdlib>
#include <iostream>
using namespace std;
map<pair<int,int>,int> num;
int a[4],b[4],x[4],y[4];
int main()
{
	int l[2],w[2],curl=0,curw=0;
	for(int i=0;i<4;i++)
	{
		cin>>a[i]>>b[i]>>x[i]>>y[i];
		num[{a[i],b[i]}]++;
		num[{x[i],y[i]}]++;
		if(a[i]==x[i])
		{
			w[curw]=abs(b[i]-y[i]);
			curw++;
		}
		else
		{
			l[curl]=abs(a[i]-x[i]);
			curl++;
		}
	}
	bool ok=true;
	for(map<pair<int,int>,int>::iterator it=num.begin();it!=num.end();it++)
	{
		if(it->second!=2)	ok=false;
	}
	if(curw==2&&curl==2&&l[0]==l[1]&&w[0]==w[1]&&l[0]>0&&w[0]>0&&ok)
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	return 0;
}