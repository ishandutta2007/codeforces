#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N=100050;
int a[N],b[N];
//vector<int> Bad[N];
/*bool bad(int x, int y)
{
	int i;
	for(i=0;i<Bad[x].size();i++) if(Bad[x][i]==y) return true;
	return false;
}*/
int x[N],y[N];
void Swap(int &a, int &b)
{
	a^=b;
	b^=a;
	a^=b;
}
bool bad(int u, int v)
{
	if(v<u) Swap(u,v);
	if(x[u]+1==x[v] && y[u]==y[v]) return 1;
	if(x[u]==x[v] && y[u]+1==y[v]) return 1;
	return 0;
}
set< pair<int,int> > Set;
set< pair<int,int> >::iterator it;
int main()
{
	srand(time(0));
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=0;i<n*m;i++)
	{
		a[i]=i;
		x[i]=i/m;
		y[i]=i%m;
		//if((i-1)%m!=0) Bad[i].push_back(i-1);
		//if(i%m!=0) Bad[i].push_back(i+1);
		//if(i>m) Bad[i].push_back(i-m);
		//if(i+m<=n*m) Bad[i].push_back(i+m);
	}
	//for(i=1;i<=n*m;i++) printf("%i %i\n",x[i],y[i]);
	while(clock()<=1.9*CLOCKS_PER_SEC)
	{
		//printf(":D\n");
		random_shuffle(a,a+n*m);
		bool ok=1;
		Set.clear();
		for(i=0;i<n*m;i++) Set.insert(make_pair(i,a[i]));
		for(i=0;i<n*m;i++)
		{
			bool done=0;
			for(it=Set.begin();it!=Set.end();it++)
			{
				done=1;
				b[i]=it->second;
				if(i/m && bad(b[i],b[i-m])) done=0;
				if(i%m && bad(b[i],b[i-1])) done=0;
				if(done){ Set.erase(it);break;}
			}
			if(!done){ ok=0;break;}
		}
		/*for(i=1;i<=n*m;i++)
		{
			//if((i-1)%m!=0) if(bad(a[i],a[i-1])){ ok=false;break;}
			if(i%m!=0) if(bad(a[i],a[i+1])){ ok=false;break;}
			//if(i>m) if(bad(a[i],a[i-m])){ ok=false;break;}
			if(i+m<=n*m) if(bad(a[i],a[i+m])){ ok=false;break;}
		}*/
		if(ok)
		{
			printf("YES\n");
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					printf("%i ",b[i*m+j]+1);
				}
				printf("\n");
			}
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}