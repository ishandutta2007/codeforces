//CF1168A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 333333;
int n,m,a[N];
int main()
{
	int i,l,r,h,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	l=0,r=m-1;
	while(l<r){
		h=l+r>>1;
		x=0;
		for(i=1;i<=n;i=i+1){
			if(a[i]+h<m&&x>a[i]+h)
				break;
			if(a[i]+h>=m+x)
				y=x;
			else
				y=max(x,a[i]);
			x=y;
		}
		if(i>n)
			r=h;
		else
			l=h+1;
	}
	cout<<l;
	return 0;
}