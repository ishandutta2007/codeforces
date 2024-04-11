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

int n,m,v,u;

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d%d%d",&n,&m,&v);
	int xm=(n-1)*(n-2)/2;
	if (xm+1<m||m<n-1){
		puts("-1");
		return 0;
	}
	u=(v==1)?2:1;
	--m;
	printf("%d %d\n",v,u);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (i!=u&&j!=u){
				if (!m)return 0;
				printf("%d %d\n",i,j);
				m--;
			}
	return 0;
}