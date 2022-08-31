//CF1693A
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
const int N = 222222;
int n,a[N];
LL b[N];
int main()
{
	int T,i,o;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		o=1;
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<=n;i++)
			b[i]=b[i-1]+a[i];
		for(i=1;i<=n;i++)
			if(b[i]<0||(i>1&&!b[i-1]&&b[i]))
				o=0;
		if(b[n]!=0)
			o=0;
		if(o)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}