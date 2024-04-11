//CF1662A
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
const int N = 111;
int n,a[N];
int main()
{
	int T,i,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
			scanf("%d%d",&y,&x),a[x]=max(a[x],y);
		x=0;
		for(i=1;i<=10;i++)
			x+=a[i];
		for(i=1;i<=10;i++)
			if(a[i]==0)
				x=-1;
		if(x==-1)
			printf("MOREPROBLEMS\n");
		else
			printf("%d\n",x);
	}
	return 0;
}