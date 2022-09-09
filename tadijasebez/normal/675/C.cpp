#include <stdio.h>
#include <map>
using namespace std;
#define ll long long
map<ll,int> C;
int ans;
int min(int a, int b){ return a>b?b:a;}
ll s;
int main()
{
	int n,m,t;
	scanf("%i",&n);
	ans=n,m=n;
	while(m--) scanf("%i",&t),s+=t,C[s]++,ans=min(ans,n-C[s]);
	printf("%i",ans);
	return 0;
}