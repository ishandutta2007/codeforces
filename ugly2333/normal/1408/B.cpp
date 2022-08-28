//CF1408B
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
int n,k,a[N],b[N];
int main()
{
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i=i+1)
			scanf("%d",a+i);
		x=0;
		for(i=2;i<=n;i=i+1)
			if(a[i]>a[i-1])
				x++;
		if(k==1){
			if(x==0)
				printf("1\n");
			else
				printf("-1\n");
		}
		else{
			k--;
			printf("%d\n",max(1,(x+k-1)/k));
		}
	}
	return 0;
}