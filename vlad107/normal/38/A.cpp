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

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	int n,a[1000];
	scanf("%d",&n);
	for (int i=0;i<n-1;i++)
		scanf("%d",&a[i]);
	int l,r;
	scanf("%d%d",&l,&r);
	l--;r--;
	int res=0;
	for (int i=l;i<r;i++)
		res+=a[i];
	printf("%d\n",res);
	return 0;
}