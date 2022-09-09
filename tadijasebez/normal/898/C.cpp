#include <stdio.h>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool Sub(string a, string b)
{
	bool ok=1;
	int j=b.size()-a.size();
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=b[i+j]) return 0;
	}
	return 1;
}
void Print(string a)
{
	for(int i=0;i<a.size();i++) printf("%c",a[i]);
	printf(" ");
}
bool Compare(string a, string b)
{
	return a.size()<b.size();
}
map<string, vector<string> > Map;
map<string, vector<string> >::iterator it;
char ch[100];
int main()
{
	int n,i,k,m,j;
	string name,tmp;
	scanf("%i",&n);
	while(n--)
	{
		//scanf("%s",&ch);
		//m=strlen(ch);
		//name.erase(name.begin(),name.end());
		//for(i=0;i<m;i++) name.insert(ch[i]);
		cin >> name;
		scanf("%i",&k);
		while(k--)
		{
			//scanf("%s",&ch);
			//tmp.erase(tmp.begin(),tmp.end());
			//for(i=0;i<m;i++) tmp.insert(ch[i]);
			cin >> tmp;
			Map[name].push_back(tmp);
		}
	}
	int cnt=0;
	for(it=Map.begin();it!=Map.end();it++)
	{
		cnt++;
	}
	printf("%i\n",cnt);
	for(it=Map.begin();it!=Map.end();it++)
	{
		vector<string> v=it->second;
		vector<string> sol;
		sort(v.begin(),v.end(),Compare);
		for(i=0;i<v.size();i++)
		{
			bool sub=0;
			for(j=i+1;j<v.size();j++)
			{
				if(Sub(v[i],v[j])) sub=1;	
			}
			if(!sub) sol.push_back(v[i]);
		}
		//Print(it->first);
		cout << it->first;
		printf(" %i ",sol.size());
		for(i=0;i<sol.size();i++) cout << sol[i] << " ";//Print(sol[i]);
		printf("\n");
	}
	return 0;
}