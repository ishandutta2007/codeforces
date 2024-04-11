//CF1648B
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
const int N = 1111111;
int n,m,a[N],b[N];

int main()
{
	int T,i,j,f,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%d",&x),a[x]=1;
		for(i=1;i<=m;i++)
			b[i]=b[i-1]+a[i];
		f=1;
		for(i=1;i<=m;i++)
			for(j=1;i*j<=m;j++)
				if(a[i]&&!a[j]&&b[min(m,i*j+i-1)]!=b[i*j-1])
					f=0;
		if(f)
			printf("Yes\n");
		else
			printf("No\n");
		for(i=0;i<=m+1;i++)
			a[i]=0,b[i]=0;
	}
	return 0;
}