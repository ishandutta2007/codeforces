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

int n,x,a[222],k=0,sum[222];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&x);
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int i=0;i<n;i++)sum[i]=a[i]*(n-i);
	std::sort(sum,sum+n);
	int i=0,s=0;
	while (i<n&&s+sum[i]<=x){
		s+=sum[i];
		++i;
	}
	printf("%d\n",i);
	return 0;
}