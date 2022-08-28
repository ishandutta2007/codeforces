//CF1641B
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
const int N = 555;
int n,a[N];
vector<int> v0,v1,g;
void go(int x,int y){
	v0.push_back(x);
	v1.push_back(y);
}
int main()
{
	int T,i,j,x,y,fl;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		fl=1;
		v0.clear(),v1.clear(),g.clear();
		for(i=n;i>=1;i--){
			x=i-1;
			while(x&&a[x]!=a[i]){
				x--;
			}
			if(x==0){
				fl=0;
				break;
			}
			y=x-1;
			for(j=i-1;j>x;j--)
				go(y,a[j]),y++;
			g.push_back((i-x)*2);
			reverse(a+x,a+i);
			i--;
		}
		if(fl){
			printf("%d\n",v0.size());
			for(i=0;i<v0.size();i++)
				printf("%d %d\n",v0[i],v1[i]);
			printf("%d\n",g.size());
			for(i=g.size();i--;)
				printf("%d ",g[i]);
			printf("\n");
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}