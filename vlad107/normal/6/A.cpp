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

int a[10];

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	for (int i=0;i<4;i++)
		scanf("%d",&a[i]);
	bool t1=false,t2=false;
	for (int i=0;i<2;i++)
		for (int j=i+1;j<3;j++)
			for (int k=j+1;k<4;k++){
				if (a[i]+a[j]==a[k]&&a[i]+a[k]>a[j]&&a[j]+a[k]>a[i])t2=true;
				if (a[i]+a[j]>a[k]&&a[i]+a[k]==a[j]&&a[j]+a[k]>a[i])t2=true;
				if (a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]&&a[j]+a[k]==a[i])t2=true;
				if (a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]&&a[j]+a[k]>a[i])t1=true;
			}
	if (t1)puts("TRIANGLE");else
	if (t2)puts("SEGMENT");else
	puts("IMPOSSIBLE");
	return 0;
}