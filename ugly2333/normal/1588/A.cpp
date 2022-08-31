//CF1588A
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
const int N = 1111;
const int B = 111;
int n,a[N],b[N],c[N],d[N],e[N];
int main()
{
	int T,i,x,o;
	scanf("%d",&T);
	while(T--){
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i),a[i]+=B,c[a[i]]++;
		for(i=1;i<=n;i++)
			scanf("%d",b+i),b[i]+=B,d[b[i]]++;
		x=1;
		for(i=B*2;i>=1;i--){
			if(c[i]+c[i-1]<d[i]){
				x=0;
				break;
			}
			o=max(0,d[i]-c[i]);
			c[i]+=o,c[i-1]-=o;
		}
		if(x)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}