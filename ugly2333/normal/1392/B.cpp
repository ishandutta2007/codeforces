//CF1392B
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
void go(){
	int i,x;
	x=a[1];
	for(i=1;i<=n;i=i+1)
		x=max(x,a[i]);
	for(i=1;i<=n;i=i+1)
		a[i]=x-a[i];
}
int main()
{
	int T,i;
	LL k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&k);
		for(i=1;i<=n;i=i+1)
			scanf("%d",a+i);
		if(k&1)
			go();
		else
			go(),go();
		for(i=1;i<=n;i=i+1)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}