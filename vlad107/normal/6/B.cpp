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

const int hx[]={1,-1,0,0};
const int hy[]={0,0,-1,1};
int qb=0,qe=1,qx[10000],qy[10000],n,m,res=0;
char a[1000][1000],C;
bool was[1000];


int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d%d %c\n",&n,&m,&C);
	for (int i=0;i<n;i++)gets(a[i]);
	memset(was,false,sizeof(was));
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (a[i][j]==C)
				for (int q=0;q<4;q++){
					int cx=i+hx[q],
					    cy=j+hy[q];
					if (cx<0||cy<0||cx>=n||cy>=m)continue;
					if (a[cx][cy]=='.')continue;
					was[a[cx][cy]-'A']=true;
				}
	for (int q=0;q<26;q++)
		if (q!=C-'A'&&was[q])res++;
	printf("%d\n",res);
	return 0;
}