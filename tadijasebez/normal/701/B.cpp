#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
int r[N],c[N];
int main()
{
	int R,C,n,m;
	scanf("%i %i",&n,&m);
	R=C=n;
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%i %i",&x,&y);
		R-=1-r[x];r[x]=1;
		C-=1-c[y];c[y]=1;
		printf("%lld ",(ll)R*C);
	}
	return 0;
}