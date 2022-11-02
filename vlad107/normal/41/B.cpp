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

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	int n,b;
	scanf("%d%d",&n,&b);
	int r=0,c=1000000000,k=-1,o;
	for (int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		int q=b/c;
		if (b+q*(x-c)>r){
			r=b+q*(x-c);
			k=c;
			o=x;
		}
		c=std::min(c,x);
	}
	if (k<0){
		printf("%d\n",b);
		return 0;
	}
	int q=b/k;
	printf("%d\n",b+q*(o-k));
	return 0;
}