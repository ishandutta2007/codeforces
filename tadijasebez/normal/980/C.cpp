#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
#define ll long int
#define pb push_back
#define mp make_pair
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
const int N=100050;
int a[N];
bool was[256];
int go[256];
set<pair<int,int> > Set;
set<pair<int,int> >::iterator it;
pair<int,int> find(int i)
{
	it=Set.lower_bound(mp(i,N));
	if(it==Set.begin()) return mp(-1,-1);
	it--;return *it;
}
int main()
{
	int n,i,k,j,l;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		pair<int,int> tmp=find(a[i]);
		if(tmp.second>=a[i]) a[i]=tmp.first;
		else
		{
			int L,R;
			if(tmp.first==-1)
			{
				L=max(0,a[i]-k+1);
				R=a[i];
				a[i]=L;
				Set.insert(mp(L,R));
			}
			else
			{
				if(a[i]-tmp.first<k)
				{
					L=tmp.first;
					R=a[i];
					a[i]=L;
					Set.erase(tmp);
					Set.insert(mp(L,R));
				}
				else
				{
					L=max(tmp.second+1,a[i]-k+1);
					R=a[i];
					a[i]=L;
					Set.insert(mp(L,R));
				}
			}
			/*L=a[i];while(L>0 && a[i]-L+1<k && !was[L-1]) L--;
			R=a[i];while(R<255 && R+1-a[i]<k && !was[R+1]) R++;
			for(j=0;j<k && j+L<=R;j++)
			{
				was[L+j]=1;go[L+j]=L;
			}
			//printf("%i %i %i\n",i,L,R);
			a[i]=go[a[i]];*/
		}
	}
	for(i=1;i<=n;i++) printf("%i ",a[i]);
	return 0;
}