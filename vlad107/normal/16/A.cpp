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

int n,m;
char a[111][111];

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d%d\n",&n,&m);
	for (int i=0;i<n;i++){
		gets(a[i]);
		for (int j=1;j<m;j++)
			if (a[i][j]!=a[i][j-1]){
				puts("NO");
				return 0;
			}
		if (i&&a[i][0]==a[i-1][0]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}