#include <stdio.h>
#include <set>
using namespace std;
#define mp make_pair
const int N=400050;
int a[N],b[N],c[N];
bool has[N];
set<pair<int,int> > book;
int sol;
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),c[b[a[i]]]=i,b[a[i]]=i;
	//for(i=1;i<=n;i++) printf("%i ",c[i]);printf("\n");
	int sz=0;
	for(i=1;i<=n;i++)
	{
		if(!has[a[i]])
		{
			if(book.size()==k) has[book.rbegin()->second]=0,book.erase(--book.end());
			sol++;
			if(c[i])
			{
				book.insert(mp(c[i],a[i]));
				has[a[i]]=1;
			}
		}
		else
		{
			book.erase(mp(i,a[i]));
			if(c[i]) book.insert(mp(c[i],a[i]));
			else has[a[i]]=0;
		}
	}
	printf("%i\n",sol);
	return 0;
}