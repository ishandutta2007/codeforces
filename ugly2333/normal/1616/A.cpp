//CF1616A
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
int n,m=105,a[N];
int main()
{
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			a[abs(x)]++;
		}
		x=0;
		for(i=0;i<=m;i++)
			x+=min(1+(i!=0),a[i]),a[i]=0;
		printf("%d\n",x);
	}
	return 0;
}