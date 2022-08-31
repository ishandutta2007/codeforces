//CF1548A
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
int n,m,q,s,a[N];
int main()
{
	int i,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		x=min(x,y);
		a[x]++;
	}
	for(i=1;i<=n;i++)
		if(!a[i])
			s++;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&i);
		if(i==3)
			printf("%d\n",s);
		else{
			scanf("%d%d",&x,&y);
			x=min(x,y);
			if(i==1){
				if(!a[x])
					s--;
				a[x]++;
			}
			else{
				a[x]--;
				if(!a[x])
					s++;
			}
		}
	}
	return 0;
}