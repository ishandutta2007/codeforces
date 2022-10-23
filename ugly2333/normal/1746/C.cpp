//CF1746C
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
int n,a[N],b[N];
set<int> S;
int main()
{
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		S.clear();
		for(i=1;i<=n;i++)
			scanf("%d",a+i),S.insert(i),b[i]=1;
		for(i=2;i<=n;i++)
			if(a[i-1]>a[i])
				x=*S.lower_bound(a[i-1]-a[i]),b[x]=i,S.erase(x);
		for(i=1;i<=n;i++)
			printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}