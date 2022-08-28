//CF1465A
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
int n,m,a[N];
int main()
{
	int T,i,x,y,s;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i=i+1){
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		s=0;
		for(i=1;i<=n;i=i+1){
			if(!a[i])
				continue;
			if(a[i]==i){
				a[i]=0;
				continue;
			}
			x=i;
			while(1){
				y=a[x];
				a[x]=0;
				x=y;
				if(!x)
					break;
				s++;
				if(x==i){
					s++;
					break;
				}
			}
		}
		printf("%d\n",s);
	}
	return 0;
}