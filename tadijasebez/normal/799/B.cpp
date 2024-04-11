#include <stdio.h>
#include <set>
using namespace std;
const int N=200050;
struct Data
{
	int p,a,b;
	Data(){}
	Data(int pp, int aa, int bb){p=pp,a=aa,b=bb;}
	inline bool operator < (const Data &v) const{return p<v.p;}
};
set<Data> Set[4];
set<Data>::iterator it;
int Solve(int x)
{//printf(":D\n");
	if(Set[x].empty()) return -1;
	it=Set[x].begin();
	int p=it->p,a=it->a,b=it->b;
	if(a==b) Set[a].erase(Data(p,a,b));
	else{
		Set[a].erase(Data(p,a,b));
		Set[b].erase(Data(p,a,b));
	}
	return p;
}
void Add(int p, int a, int b)
{
	if(a==b) Set[a].insert(Data(p,a,b));
	else{
		Set[a].insert(Data(p,a,b));
		Set[b].insert(Data(p,a,b));
	}
}
int p[N],a[N],b[N];
int main()
{
	int n,q,i,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&p[i]);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) scanf("%i",&b[i]);
	for(i=1;i<=n;i++) Add(p[i],a[i],b[i]);
	scanf("%i",&q);
	while(q--) scanf("%i",&x),printf("%i ",Solve(x));
	printf("\n");
	return 0;
}