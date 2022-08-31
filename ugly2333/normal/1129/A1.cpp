//CF1129A
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
const int N = 5555;
int n,m,a[N],b[N];
int main()
{
	int i,j,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1)
		b[i]=n;
	while(m--){
		scanf("%d%d",&x,&y);
		a[x]++;
		b[x]=min(b[x],(y-x+n)%n);
	}
	for(i=1;i<=n;i=i+1){
		x=0;
		for(j=1;j<=n;j=j+1)
			if(a[j])
				x=max(x,n*(a[j]-1)+b[j]+(j-i+n)%n);
		printf("%d ",x);
	}
	return 0;
}