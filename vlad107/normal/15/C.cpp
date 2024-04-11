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

long long res=0;
int tt;

long long f(long long x){
	if ((x+1)%4==0)return 0;
	if ((x+1)%2==0)return 1;
	if (x%4==2)return 1+x;
	if (x%4==0)return x;
}

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d",&tt);
	while (tt){
		--tt;
		long long x,y;
		scanf("%I64d%I64d",&x,&y);
		res^=f(x+y-1);
		res^=f(x-1);
	}
	puts(res?"tolik":"bolik");
	return 0;
}