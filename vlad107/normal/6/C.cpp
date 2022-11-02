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

#define N 100100

int x=0,y=0,n,s1[N],s2[N],a[N];

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	s1[0]=0;
	for (int i=1;i<=n;i++)
		s1[i]=s1[i-1]+a[i];
	s2[n+1]=0;
	for (int i=n;i>=1;i--)
		s2[i]=s2[i+1]+a[i];
	for (int i=1;i<=n;i++)
		if (s1[i-1]<=s2[i+1])
			x++;
		else y++;
	printf("%d %d\n",x,y);
	return 0;
}