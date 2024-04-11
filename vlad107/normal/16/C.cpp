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

int GCD(int a,int b){
	while (a&&b)if (a>b)a%=b;else b%=a;
	return a+b;
}

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int x=GCD(c,d);
	c/=x;d/=x;
	x=std::min(a/c,b/d);
	printf("%d %d\n",c*x,d*x);
	return 0;
}