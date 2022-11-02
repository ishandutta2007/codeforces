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

bool a[10];
int x,y;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);	
	scanf("%d",&x);
	memset(a,false,sizeof(a));
	a[x]=true;
	for (int i=1;i<4;i++){
		scanf("%d%d",&x,&y);
		std::swap(a[x],a[y]);
	}
	for (int i=1;i<4;i++)
		if (a[i]){
			printf("%d\n",i);
			return 0;
		}
	return 0;
}