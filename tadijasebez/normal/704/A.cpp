#include <stdio.h>
#include <set>
using namespace std;
const int N=300050;
set<int> Set,X[N];
int c,Y[N];
int main()
{
	int n,q,t,x,i;
	set<int>::iterator it,it1,it2;
	scanf("%i %i",&n,&q);
	while(q--)
	{
		scanf("%i %i",&t,&x);
		if(t==1) c++,Y[c]=x,X[x].insert(c),Set.insert(c);
		if(t==2){
			for(it=X[x].begin();it!=X[x].end();it++) Set.erase(*it);
			X[x].clear();
		}
		if(t==3){
			it1=Set.begin();
			while(it1!=Set.end() && *it1<=x)
			{
				X[Y[*it1]].erase(*it1);
				it2=it1;
				it1++;
				Set.erase(it2);
			}
		}
		printf("%i\n",Set.size());
	}
	return 0;
}