//CF1608C
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
const int N = 111111;
int n,a[N],b[N],pa[N],pb[N],f[N];
bool cmpa(int i,int j){
	return a[i]>a[j];
}
bool cmpb(int i,int j){
	return b[i]>b[j];
}
int main()
{
	int T,i,j,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<=n;i++)
			scanf("%d",b+i);
		for(i=1;i<=n;i++)
			pa[i]=i,pb[i]=i,f[i]=0;
		sort(pa+1,pa+n+1,cmpa);
		sort(pb+1,pb+n+1,cmpb);
		x=a[pa[1]],y=b[pb[1]];
		i=1,j=1;
		while(1){
			if(i<=n&&a[pa[i]]>=x||b[pa[i]]>=y){
				f[pa[i]]=1;
				x=min(x,a[pa[i]]);
				y=min(y,b[pa[i]]);
				i++;
			}
			else{
				if(j<=n&&a[pb[j]]>=x||b[pb[j]]>=y){
					f[pb[j]]=1;
					x=min(x,a[pb[j]]);
					y=min(y,b[pb[j]]);
					j++;
				}
				else
					break;
			}
		}
		for(i=1;i<=n;i++)
			printf("%d",f[i]);
		printf("\n");
	}
	return 0;
}