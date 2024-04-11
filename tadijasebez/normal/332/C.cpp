#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back
const int N=100050;
const int inf=1e9+7;
int min(int a, int b){ return a>b?b:a;}
int a[N],b[N],id[N];
vector<int> ids;
bool comp1(int i, int j){ return (b[i]==b[j] && a[i]>a[j]) || b[i]<b[j];}
bool comp2(int i, int j){ return (a[i]==a[j] && b[i]>b[j]) || a[i]>a[j];}
bool comp3(int i, int j){ return b[i]>b[j];}
int main()
{
	int n,p,k,m,i;
	scanf("%i %i %i",&n,&p,&k);
	m=p-k;
	for(i=1;i<=n;i++) scanf("%i %i",&a[i],&b[i]),id[i]=i;
	sort(id+1,id+1+n,comp1);
	sort(id+1+m,id+1+n,comp2);
	int Min=0;
	for(i=m+1;i<=p;i++) printf("%i ",id[i]),Min=!Min?id[i]:comp1(id[i],Min)?id[i]:Min;
	for(i=1;i<=m;i++) if(!Min || comp1(id[i],Min) || (a[id[i]]==a[Min] && b[id[i]]==b[Min])) ids.pb(id[i]);
	for(i=p+1;i<=n;i++) if(!Min || comp1(id[i],Min) || (a[id[i]]==a[Min] && b[id[i]]==b[Min])) ids.pb(id[i]);
	sort(ids.begin(),ids.end(),comp3);
	for(i=0;i<m;i++) printf("%i ",ids[i]);
	printf("\n");
	return 0;
}