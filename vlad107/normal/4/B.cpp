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

#define N 1000

int n,m,a[N],b[N],c[N];

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++){
		scanf("%d%d",&a[i],&b[i]);
		c[i]=b[i];
		m-=b[i];
	}
	while (m!=0){
		bool good=false;
		for (int i=0;i<n;i++)
			if (c[i]>a[i]){
				c[i]--;
				good=true;
				m++;
				break;
			}
		if(!good)break;
	}                  
	if (m!=0)
		printf("NO\n");
	else{
		printf("YES\n");
		for (int i=0;i<n;i++)
			printf("%d ",c[i]);
	}
	return 0;
}