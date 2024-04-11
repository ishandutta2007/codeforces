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

int n,m;

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d",&n);
	m=n/2;
	printf("%d\n",m*(n-m));
	for (int i=1;i<=m;i++)
		for (int j=m+1;j<=n;j++)
			printf("%d %d\n",i,j);
	return 0;
}