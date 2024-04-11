// CF 814D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
struct cir{
	int r;
	int x;
	int y;
	int f;
}a[1111];
bool cmpr(cir al,cir bl){
	return al.r>bl.r;
}
bool isin(cir al,cir bl){
	LL dis,xx,yy;
	xx=al.x-bl.x;
	yy=al.y-bl.y;
	dis=(LL)xx*xx+yy*yy;
	if((LL)al.r*al.r>=dis){
		return 1;
	}
	return 0;
}
LL ans;
double anss;
int main()
{
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>a[i].x>>a[i].y>>a[i].r;
		a[i].f=0;
	}
	sort(a+1,a+n+1,cmpr);
	ans=0;
	for(i=1;i<=n;i=i+1){
		for(j=i-1;j>=1;j=j-1){
			if(isin(a[j],a[i]))
				break;
		}
		//cout<<j<<endl;
		if(j==0){
			a[i].f=2;
			ans+=(LL)a[i].r*a[i].r;
			continue;
		}
		if(a[j].f==2){
			a[i].f=1;
			ans+=(LL)a[i].r*a[i].r;
			continue;
		}
		a[i].f=-a[j].f;
		ans+=(LL)a[i].r*a[i].r*a[i].f;
	}
	anss=(double)ans*3.14159265358979328462643383279;
	printf("%.8lf",anss);
	return 0;
}