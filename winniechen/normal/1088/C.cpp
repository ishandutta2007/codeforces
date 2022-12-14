#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <bitset>
using namespace std;
#define N 2050
int n,a[N];
int op[N],oa[N],ob[N];
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	op[1]=1; oa[1]=n; ob[1]=100000;
	for(i=1;i<=n;i++) a[i]+=100000;
	int now=-1;
	for(i=1;i<=n;i++) {
		op[i+1]=2; oa[i+1]=i; ob[i+1]=a[i]-now-1;
		now=a[i]%ob[i+1];
	}
	printf("%d\n",n+1);
	for(i=1;i<=n+1;i++) printf("%d %d %d\n",op[i],oa[i],ob[i]);
}