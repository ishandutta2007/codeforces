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

int n,m,a;

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	n=n/a+(n%a>0);
	m=m/a+(m%a>0);
	printf("%I64d\n",(long long)n*m);
	return 0;
}