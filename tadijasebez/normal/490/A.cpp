#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
int min(int a, int b){ return a>b?b:a;}
int main()
{
	vector<int> a[4];
	int n,i,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&x),a[x].pb(i);
	int sz=min(a[1].size(),min(a[2].size(),a[3].size()));
	printf("%i\n",sz);
	for(i=0;i<sz;i++) printf("%i %i %i\n",a[1][i],a[2][i],a[3][i]);
	return 0;
}