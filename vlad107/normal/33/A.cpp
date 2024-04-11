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

int a[1000000];

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	int n,m,mr;
	scanf("%d%d%d",&n,&m,&mr);
	memset(a,-1,sizeof(a));
	for (int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		--x;
		if (a[x]<0)
			a[x]=y;
		else a[x]=std::min(a[x],y);
	}
	int res=0;
	for (int i=0;i<m;i++)
		res+=a[i];
	if (res>mr)res=mr;
	printf("%d\n",res);
	return 0;
}