//CF 995D
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
const int N = 1<<19;
int n,q,a[N];
LL s;
int main()
{
	int i,x,y;
	scanf("%d%d",&n,&q);
	n=1<<n;
	for(i=0;i<n;i=i+1)
		scanf("%d",a+i),s+=a[i];
	for(i=0;i<=q;i=i+1){
		if(i){
			scanf("%d%d",&x,&y);
			s-=a[x];
			a[x]=y;
			s+=a[x];
		}
		printf("%.9f\n",(DB)s/n);
	}
	return 0;
}