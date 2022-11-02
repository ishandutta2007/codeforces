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

int n,min1,min2,x[1000],i;

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++)scanf("%d",&x[i]);
	std::sort(x,x+n);
	int i=1;
	while (i<n&&x[i]==x[0])i++;
	if (i<n)
		printf("%d\n",x[i]);
	else puts("NO");
	return 0;
}