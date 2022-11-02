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

int n ,x,y,tt,z,d[1000][1000];

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++)for (int j=0;j<n;j++)
		scanf("%d",&d[i][j]);
	scanf("%d",&tt);
	while (tt){
		tt--;
		scanf("%d%d%d",&x,&y,&z);
		x--;y--;
		d[x][y]=std::min(d[x][y],z);
		d[y][x]=std::min(d[y][x],z);
		for (int i=0;i<n;i++) for (int j=0;j<n;j++)
			if (d[i][x]+d[x][y]+d[y][j]<d[i][j])d[i][j]=d[i][x]+d[x][y]+d[y][j];
		std::swap(x,y);
		for (int i=0;i<n;i++) for (int j=0;j<n;j++)
			if (d[i][x]+d[x][y]+d[y][j]<d[i][j])d[i][j]=d[i][x]+d[x][y]+d[y][j];
		long long res=0;
		for (int i=0;i<n;i++) for (int j=i;j<n;j++)res+=d[i][j];
		printf("%I64d ",res);
	}
	return 0;
}