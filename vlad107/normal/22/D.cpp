#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <limits>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <numeric>
#include <cmath>
#include <complex>
#include <list>
#include <ctime>
#include <functional>

struct Point{
	int x,y;
};

bool was[1010];
int res[1010],n,ss[1010],ff[1010],kg=0;
Point a[2020];

bool cmp(Point a,Point b){
	return a.x==b.x?a.y>b.y:a.x<b.x;
}

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&ss[i],&ff[i]);
		if (ss[i]>ff[i])std::swap(ss[i],ff[i]);
		a[kg].x=ss[i];
		a[kg++].y=i;
		a[kg].x=ff[i];
		a[kg++].y=-i;
	}
	std::sort(a,a+kg,cmp);
	memset(was,false,sizeof(was));
	res[0]=1;
	for (int i=0;i<kg;i++)
		if (a[i].y>0)was[a[i].y]=true;else{
			if (!was[-a[i].y])continue;
			res[res[0]++]=a[i].x;
			memset(was,false,sizeof(was));
		}
	printf("%d\n",res[0]-1);
	for (int i=1;i<res[0];i++)
		printf("%d ",res[i]);
	puts("");
	return 0;
}