#include <stdio.h>
#include <map>
#include <set>
using namespace std;
struct mp
{
	int c,x;
	mp(){}
	mp(int a, int b){ c=a,x=b;}
	inline bool operator < (const mp &b) const
	{
		if(c==b.c) return x>b.x;
		return c<b.c;
	}
};
map<int,int> C;
set<mp> Set;
void Add(int x)
{
	if(C[x]) Set.erase(mp(C[x],x));
	C[x]++; Set.insert(mp(C[x],x));
}
void Err(int x)
{
	Set.erase(mp(C[x],x)); C[x]--;
	if(C[x]) Set.insert(mp(C[x],x));
}
int a[100050];
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		Add(a[i]);
		if(i>k) Err(a[i-k]);
		if(i>=k)
		{
			mp tmp=*Set.begin();
			if(tmp.c==1) printf("%i\n",tmp.x);
			else printf("Nothing\n");
		}
	}
	return 0;
}