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

#define N 100100

int n,m,kb=0,x[N],a=0,bl[N],br[N];
std::multiset <int> s;

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		scanf("%d",&x[i]);
	int l=0;
	for (int r=0;r<n;r++){
		s.insert(x[r]);
		while (1){
			int o1=*s.begin();
			std::set<int>::iterator O=s.end();
			--O;
			int o2=*O;
			if (o2-o1>m){
				s.erase(s.find(x[l]));
				l++;
			}else break;
		}
		if (r-l+1>a){
			a=r-l+1;
			kb=0;
		};
		if (r-l+1==a){
			bl[kb]=l;
			br[kb++]=r;
		}
	}
	printf("%d %d\n",a,kb);
	for (int i=0;i<kb;i++)
		printf("%d %d\n",bl[i]+1,br[i]+1);
	return 0;
}