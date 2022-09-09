#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<pair<char,char> > sol;
int p[N];
void Init(){ for(int i=0;i<N;i++) p[i]=i;}
int Find(int x){ return x==p[x]?x:p[x]=Find(p[x]);}
void Union(int x, int y){ p[Find(x)]=Find(y);}
char s[N],t[N];
int main()
{
	Init();
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(i=1;i<=n;i++)
	{
		if(Find(s[i])!=Find(t[i]))
		{
			sol.push_back(make_pair(s[i],t[i]));
			Union(s[i],t[i]);
		}
	}
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%c %c\n",sol[i].first,sol[i].second);
	return 0;
}