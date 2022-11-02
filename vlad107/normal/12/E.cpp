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

int n,a[1010][1010];

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)    
			a[i][j]=1+(i+j)%(n-1);
	}           
	for (int i=1;i<=n;i++){
		a[n][i]=a[i][i];
		a[i][n]=a[i][i];
		a[i][i]=0;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		puts("");
	}
	return 0;
}