#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
int kor[(1<<16)+50];
int degree[(1<<16)+50];
set<pair<int,int> > s;
vector<pair<int,int> > sol;
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,d;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%i%i",&d,&kor[i]);
		s.insert(make_pair(d,i));
		degree[i]=d;
	}
	set<pair<int,int> >::iterator it;
	int m=n;
	while(m--)
	{
		it=s.begin();
		int x=it->second;
		if(it->first>0)
		{
			sol.push_back(make_pair(min(x,kor[x]),max(x,kor[x])));
			s.erase(make_pair(degree[kor[x]],kor[x]));
			degree[kor[x]]--;
			kor[kor[x]]^=x;
			s.insert(make_pair(degree[kor[x]],kor[x]));
		}	
		s.erase(make_pair(it->first,it->second));
	}
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i %i\n",sol[i].first,sol[i].second);
	return 0;
}