#include <stdio.h>
#include <stack>
#include <set>
using namespace std;
const int N=500050;
char Base[N];
char Query[N];
set<int> Set;
set<int>::iterator cur,it1,it2,it;
int Pair[N];
void Prepare(int n)
{
	int i;
	stack<int> s;
	for(i=1;i<=n;i++)
	{
		Set.insert(i);
		if(Base[i]=='(') s.push(i);
		else Pair[i]=s.top(),Pair[s.top()]=i,s.pop();
	}
}
void Del(int x, int y)
{
	cur=Set.upper_bound(y);
	it1=Set.lower_bound(x);
	it2=Set.upper_bound(y);
	Set.erase(it1,it2);
	if(cur==Set.end()) cur--;
}
int main()
{
	int n,q,p,i;
	scanf("%i %i %i",&n,&q,&p);
	scanf("%s",Base+1);
	Prepare(n);
	cur=Set.find(p);
	scanf("%s",Query+1);
	for(i=1;i<=q;i++)
	{
		if(Query[i]=='L') cur--;
		if(Query[i]=='R') cur++;
		if(Query[i]=='D')
		{
			int u=*cur,t=Pair[u];
			if(t<u) Del(t,u);
			else Del(u,t);
		}
	}
	for(it=Set.begin();it!=Set.end();it++) printf("%c",Base[*it]);
	printf("\n");
	return 0;
}