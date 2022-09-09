#include <stdio.h>
#include <map>
#include <set>
using namespace std;
const int N=200050;
map<int,int> id;
set<int> a,b;
char s[2*N];
int main()
{
	int n,x,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&x),a.insert(x),id[x]=i;
	scanf("%s",s+1);
	for(i=1;i<=2*n;i++)
	{
		if(s[i]=='0')
		{
			int y=*a.begin();
			a.erase(a.begin());
			printf("%i ",id[y]);
			b.insert(y);
		}
		else
		{
			int y=*b.rbegin();
			b.erase(--b.end());
			printf("%i ",id[y]);
		}
	}
	return 0;
}