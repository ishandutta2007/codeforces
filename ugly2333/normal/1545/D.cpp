//CF1545D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1111;
int n,m,a[N][N];
LL b[N],c[N],d[N];
int main()
{
	int i,j,k;
	LL db,dc,eb,ec;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			scanf("%d",a[i]+j);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			b[i]+=a[i][j],c[i]+=(LL)a[i][j]*a[i][j];
	for(i=1;i<m;i++)
		d[i]=b[i+1]-b[i];
	sort(d+1,d+m);
	db=d[3];
	for(i=1;i<=m;i++)
		if(b[i]!=b[1]+(i-1)*db)
			k=i;
	eb=b[1]+(k-1)*db-b[k];
	if(k<=3)
		dc=(c[6]-c[5])-(c[5]-c[4]);
	else
		dc=(c[3]-c[2])-(c[2]-c[1]);
	if(k==2)
		ec=c[3]*2-c[4]+dc-c[2];
	else
		ec=c[k-1]*2-c[k-2]+dc-c[k];
	cout<<k-1<<' '<<(eb+ec/eb)/2<<endl;
	return 0;
}