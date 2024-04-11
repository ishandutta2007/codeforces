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

int cr,n,m,a[1000];

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	int res=0;
	for (int i=m;i<=10000;i++){
		cr=0;
		for (int j=0;j<n;j++)
			cr+=a[j]/i;
		if (cr*i>res)res=cr*i;
	}
	printf("%d\n",res);
	return 0;
}