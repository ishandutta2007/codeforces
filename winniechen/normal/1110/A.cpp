#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100005
int b,k,a[N];
int main()
{
	scanf("%d%d",&b,&k);
	for(int i=1;i<=k;i++)scanf("%d",&a[i]);
	int ans=0;
	for(int i=1;i<k;i++)if((a[i]&1)&&(b&1))ans^=1;
	if(a[k]&1)ans^=1;
	puts(ans?"odd":"even");
}