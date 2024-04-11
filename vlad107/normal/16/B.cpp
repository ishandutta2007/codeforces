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

int n,m;
std::pair<int,int> a[N];

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
		scanf("%d%d",&a[i].second,&a[i].first);
	std::sort(a,a+m);
	long long res=0;
	for (int i=m-1;i>=0;i--){
		if (a[i].second>n){
			res+=(long long)a[i].first*n;
			break;
		}
		n-=a[i].second;
		res+=a[i].second*a[i].first;
	}
	printf("%I64d",res);
	return 0;
}