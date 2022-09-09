#include <stdio.h>
#include <map>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
map<string,string> p;
map<string,bool> vis;
vector< pair<string,string> > sol;
int main()
{
	int n,i;
	string a,b;
	scanf("%i",&n);
	while(n --> 0)
	{
		cin >> a >> b;
		vis[a]=true;
		p[b]=a;
	}
	map<string,string>::iterator it;
	for(it=p.begin();it!=p.end();it++)
	{
		if(!vis[it->first])
		{
			a=it->first;
			while(p[a].compare("")!=0) a=p[a];
			sol.push_back(make_pair(a,it->first));
		}
	}
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) cout << sol[i].first << " " << sol[i].second << "\n";
}