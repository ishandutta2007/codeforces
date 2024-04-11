//CF1394C
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
const int N = 555555;
void cmin(int&x,int y){
	if(x>y)
		x=y;
}
void cmax(int&x,int y){
	if(x<y)
		x=y;
}
char ch[N];
int n,x[N],y[N];
int main()
{
	int i,j,l,r,o,minx,maxx,miny,maxy,minz,maxz;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%s",ch);
		for(j=0;ch[j];j=j+1){
			if(ch[j]=='B')
				x[i]++;
			else
				y[i]++;
		}
	}
	l=0,r=N;
	while(l<r){
		o=(l+r)/2;
		minx=0,maxx=N,miny=0,maxy=N,minz=-N,maxz=N;
		for(i=1;i<=n;i=i+1){
			cmax(minx,x[i]-o);
			cmin(maxx,x[i]+o);
			cmax(miny,y[i]-o);
			cmin(maxy,y[i]+o);
			cmax(minz,x[i]-y[i]-o);
			cmin(maxz,x[i]-y[i]+o);
		}
		if(minx>maxx||miny>maxy||minz>maxz){
			l=o+1;
			continue;
		}
		i=minx-maxy,j=maxx-miny;
		if(j<minz||maxz<i){
			l=o+1;
			continue;
		}
		r=o;
	}
	cout<<l<<endl;
	o=l;
	minx=0,maxx=N,miny=0,maxy=N,minz=-N,maxz=N;
	for(i=1;i<=n;i=i+1){
		cmax(minx,x[i]-o);
		cmin(maxx,x[i]+o);
		cmax(miny,y[i]-o);
		cmin(maxy,y[i]+o);
		cmax(minz,x[i]-y[i]-o);
		cmin(maxz,x[i]-y[i]+o);
	}
	for(i=maxy;i>=miny;i=i-1){
		l=max(minx,minz+i),r=min(maxx,maxz+i);
		if(l<=r){
			while(r--)cout<<'B';
			while(i--)cout<<'N';
			return 0;
		}
	}
	return 0;
}