#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int r[N],c[N],a[N][N];
int main()
{
	int n,m,q,i,j,x,y;char t;
	scanf("%i %i %i",&n,&m,&q);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%i",&a[i][j]);
	for(i=1;i<=n;i++) r[i]=i;
	for(j=1;j<=m;j++) c[j]=j;
	while(q--)
	{
		scanf("\n%c %i %i",&t,&x,&y);
		if(t=='c') swap(c[x],c[y]);
		if(t=='r') swap(r[x],r[y]);
		if(t=='g') printf("%i\n",a[r[x]][c[y]]);
	}
	return 0;
}