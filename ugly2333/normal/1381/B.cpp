//CF1381B
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
const int N = 4444;
int n,a[N],f[N];
void go(int x){
	int i;
	for(i=n*2;i>=x;i=i-1)
		f[i]|=f[i-x];
}
int main()
{
	int T,i,j,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n*2;i=i+1)
			scanf("%d",a+i);
		a[n*2+1]=n*2+1;
		memset(f,0,sizeof(f));
		f[0]=1;
		x=a[1],j=1;
		for(i=2;i<=n*2+1;i=i+1){
			if(x<a[i]){
				go(i-j);
				x=a[i];
				j=i;
			}
		}
		if(f[n])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}