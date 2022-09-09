#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
set<int> s,p;
vector< vector<int> > sol;
vector<int> tmp;
bool comp(int a, int b){ return a>b;}
int main()
{
	int n,i,x,j,c;
	scanf("%i",&n);
	for(i=1;i<=n;i++) s.insert(i);
	set<int>::iterator it,it1;
	for(i=1;i<=n;i++)
	{
		tmp.clear();
		scanf("%i",&x);
		s.erase(x);
		p.insert(x);
		if(!s.empty()) it=s.end(),it--,c=*it;
		else c=0;
		it=p.upper_bound(c);
		for(it1=it;it1!=p.end();it1++)
		{
			//s.insert(*it1);
			tmp.push_back(*it1);
		}
		p.erase(it,p.end());
		sort(tmp.begin(),tmp.end(),comp);
		sol.push_back(tmp);
	}
	for(i=0;i<sol.size();i++)
	{
		for(j=0;j<sol[i].size();j++) printf("%i ",sol[i][j]);
		printf("\n");
	}
	return 0;
}