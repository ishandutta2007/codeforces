#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
map<string,int> id;
string s,t;
const int N=100050;
int a[N],b[N],r[N],cnt,sol,Max;
vector<int> v[N];
vector<int> pal;
vector< pair<int,int> > work;
bool comp(int a, int b){ return a>b;}
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		scanf("%i",&a[i]);
		if(!id[s]) id[s]=++cnt;
		b[i]=id[s];
		t.clear();
		for(j=s.size()-1;j>=0;j--) t.push_back(s[j]);
		//cout << t << " ";
		if(!id[t]) id[t]=++cnt;
		r[i]=id[t];
		//printf("%i %i\n",b[i],r[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==r[i]) pal.push_back(b[i]);
		else work.push_back(make_pair(b[i],r[i]));
		v[b[i]].push_back(a[i]);
	}
	for(i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
	for(i=0;i<work.size();i++)
	{
		int x=work[i].first;
		int y=work[i].second;
		//printf(" %i %i\n",x,y);
		if(!v[x].empty() && !v[y].empty() && (*v[x].rbegin())+(*v[y].rbegin())>0)
		{
			sol+=(*v[x].rbegin())+(*v[y].rbegin());
			v[x].pop_back();
			v[y].pop_back();
		}
	}
	//printf("%i\n",sol);
	sort(pal.begin(),pal.end());
	pal.erase(unique(pal.begin(),pal.end()),pal.end());
	for(i=0;i<pal.size();i++)
	{
		int x=pal[i];
		sort(v[x].begin(),v[x].end(),comp);
		for(j=1;j<v[x].size();j+=2)
		{
			if(v[x][j]+v[x][j-1]>0)
			{
				sol+=v[x][j]+v[x][j-1];
				Max=max(Max,-v[x][j]);
			}
			else break;
		}
		j--;
		if(j<v[x].size() && v[x][j]>0) Max=max(Max,v[x][j]);
	}
	printf("%i\n",sol+Max);
	return 0;
}