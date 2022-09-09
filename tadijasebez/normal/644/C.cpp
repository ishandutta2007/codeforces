#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define pb push_back
const int N=100050;
string h[N],p[N],t,a,b;
map<string,vector<string> > Map,sol;
map<string,vector<string> >::iterator it;
bool comp(string a, string b){ return a.compare(b)>0;}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		a="";b="";
		cin >> t;
		for(j=7;j<t.size() && t[j]!='/';j++) a+=t[j];
		if(j==t.size()) b=" ";
		for(;j<t.size();j++) b+=t[j];
		b+='$';
		Map[a].pb(b);
	}
	vector<string> tmp;
	int m=0;
	for(it=Map.begin();it!=Map.end();it++)
	{
		h[++m]=it->first;
		tmp=it->second;
		sort(tmp.begin(),tmp.end(),comp);
		tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
		for(i=0;i<tmp.size();i++) p[m]+=tmp[i];
		sol[p[m]].pb(h[m]);
	}
	int cnt=0;
	for(it=sol.begin();it!=sol.end();it++)
	{
		if(it->second.size()>1) cnt++;
	}
	printf("%i\n",cnt);
	for(it=sol.begin();it!=sol.end();it++)
	{
		tmp=it->second;
		//cout << it->first << "\n";
		if(tmp.size()>1)
		{
			for(i=0;i<tmp.size();i++)
			{
				printf("http://");
				cout << tmp[i];
				printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}