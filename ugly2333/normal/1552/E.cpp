//CF1552E
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
const int N = 11111;
int n,k,a[N],b[N],p[N],f[N],g[N];
void solve(int l,int r){
	int i,j;
	for(i=1;i<=n*k;i++){
		if(b[a[i]]||a[i]<l||a[i]>r)
			continue;
		if(p[a[i]]){
			f[a[i]]=p[a[i]],g[a[i]]=i,b[a[i]]=1;
			for(j=l;j<=r;j++)
				p[j]=0;
		}
		else
			p[a[i]]=i;
	}
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n*k;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i+=k-1)
		solve(i,min(i+k-2,n));
	for(i=1;i<=n;i++)
		printf("%d %d\n",f[i],g[i]);
	return 0;
}