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

char a[100][100];
int n,m,res=0;

bool ok(int sx,int sy,int ex,int ey){
	for (int i=sx;i<ex;i++)
		for (int j=sy;j<ey;j++)
			if (a[i][j]=='1')
				return false;
	return true;
}

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d%d\n",&n,&m);
	for (int i=0;i<n;i++)
		gets(a[i]);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			for (int x=i;x<n;x++)
				for (int y=j;y<m;y++)if(ok(i,j,1+x,1+y)){
					int P=(x-i+1)*2+(y-j+1)*2;
					if (P>res){
						res=P;
					}
				}
	printf("%d\n",res);				
	return 0;
}