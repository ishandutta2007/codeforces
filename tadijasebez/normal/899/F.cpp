#include <stdio.h>
#include <set>
using namespace std;
set<int> Set[1000];
set<int>::iterator it;
const int N=200050;
bool done[N];
int BIT[N];
void SetF(int i){ for(;i<N;i+=i&-i) BIT[i]++;}
int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=BIT[i];return ret;}
char ch[N];
int main()
{
	int n,m,l,r,i;
	scanf("%i %i",&n,&m);
	scanf("%s",ch+1);
	for(i=1;i<=n;i++)
	{
		Set[ch[i]].insert(i);
	}
	char t;
	while(m--)
	{
		scanf("%i %i %c",&l,&r,&t);
		int top=n,bot=1,mid,ans;
		while(top>=bot)
		{
			mid=top+bot>>1;
			//printf("%i\n",mid);
			if(mid-Get(mid)<l) bot=mid+1;
			else ans=mid,top=mid-1;
		}
		l=ans;
		top=n,bot=1;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(mid-Get(mid)<=r) ans=mid,bot=mid+1;
			else top=mid-1;
		}
		r=ans;
		//printf("%i %i\n",l,r);
		for(it=Set[t].lower_bound(l);it!=Set[t].upper_bound(r);it++)
		{
			done[*it]=1;
			SetF(*it);
		}
		Set[t].erase(Set[t].lower_bound(l),Set[t].upper_bound(r));
	}
	for(i=1;i<=n;i++)
	{
		if(!done[i]) printf("%c",ch[i]);
	}
	return 0;
}