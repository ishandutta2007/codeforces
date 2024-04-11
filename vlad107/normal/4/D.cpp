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

#define N 5555

struct Point{
	int x,y,nom;
};

int n,f[N],X,Y,p[N];
Point a[N];

bool cmp(Point a,Point b){
	return a.x==b.x?a.y>b.y:a.x>b.x;
};

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d",&n);
	scanf("%d%d",&X,&Y);
	for (int i=0;i<n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].nom=i+1;
	}
	std::sort(a,a+n,cmp);
	memset(f,0,sizeof(f));
	memset(p,-1,sizeof(p));
	for (int i=0;i<n;i++){
		if (1>f[i])f[i]=1;
		for (int j=i+1;j<n;j++)
			if (a[j].x<a[i].x&&a[j].y<a[i].y&&f[i]+1>f[j])
				f[j]=f[i]+1,p[j]=i;
	}
	int r=-1,mr=0;
	for (int i=0;i<n;i++)
		if (a[i].x>X&&a[i].y>Y&&f[i]>mr)
			mr=f[i],r=i;
	printf("%d\n",mr);
	while (r>-1){
		printf("%d ",a[r].nom);
		r=p[r];
	}
	return 0;
}