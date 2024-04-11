//CF 845E
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
struct node{
	int x;
	int y;
	int id;
}a[555],sx[555],sy[555];
bool cmpx(node al,node bl){
	return al.x<bl.x;
}
bool cmpy(node al,node bl){
	return al.y<bl.y;
}

int n,m,k,r;
int p[555];

bool checkx(int xx){
	int i,sp;
	if(xx<=0||xx>n)
		return 1;
	sp=0;
	for(i=1;i<=k;i=i+1)
		if(sy[i].x-r<=xx&&xx<=sy[i].x+r){
			sp++;
			p[sp]=sy[i].y-r;
		}
	sp++;
	p[sp]=m+1;
	if(p[1]>1)
		return 1;
	for(i=2;i<=sp;i=i+1)
		if(p[i]-p[i-1]>r+r+1)
			return 1;
	return 0;
}

bool checky(int yy){
	int i,sp;
	if(yy<=0||yy>m)
		return 1;
	sp=0;
	for(i=1;i<=k;i=i+1)
		if(sx[i].y-r<=yy&&yy<=sx[i].y+r){
			sp++;
			p[sp]=sx[i].x-r;
		}
	sp++;
	p[sp]=n+1;
	if(p[1]>1)
		return 1;
	for(i=2;i<=sp;i=i+1)
		if(p[i]-p[i-1]>r+r+1)
			return 1;
	return 0;
}

bool ok(int w){
	r=w;
	int i,j,minx,maxx,miny,maxy;
	
	if(checkx(1))
		minx=1;
	else{
		for(i=1;i<=k;i=i+1){
			if(checkx(sx[i].x+r+1)){
				minx=sx[i].x+r+1;
				break;
			}
		}
	}
	minx=min(minx,n+1);
	
	if(checkx(n))
		maxx=n;
	else{
		for(i=k;i>=1;i=i-1){
			if(checkx(sx[i].x-r-1)){
				maxx=sx[i].x-r-1;
				break;
			}
		}
	}
	maxx=max(maxx,0);
	
	if(checky(1))
		miny=1;
	else{
		for(i=1;i<=k;i=i+1){
			if(checky(sy[i].y+r+1)){
				miny=sy[i].y+r+1;
				break;
			}
		}
	}
	miny=min(miny,m+1);
	
	if(checky(m))
		maxy=m;
	else{
		for(i=k;i>=1;i=i-1){
			if(checky(sy[i].y-r-1)){
				maxy=sy[i].y-r-1;
				break;
			}
		}
	}
	maxy=max(maxy,0);
	//cout<<r<<minx<<maxx<<miny<<maxy<<endl;
	minx=max(maxx-minx+1,0)/2;
	miny=max(maxy-miny+1,0)/2;
	w=max(minx,miny);
	return (w<=r);
}

int main()
{
	int i,l,r,md;
	cin>>n>>m>>k;
	for(i=1;i<=k;i=i+1){
		cin>>a[i].x>>a[i].y;
		a[i].id=i;
		sx[i].x=a[i].x;
		sx[i].y=a[i].y;
		sx[i].id=i;
		sy[i].x=a[i].x;
		sy[i].y=a[i].y;
		sy[i].id=i;
	}
	sort(sx+1,sx+k+1,cmpx);
	sort(sy+1,sy+k+1,cmpy);
	l=0;
	r=max(n,m);
	while(l<r){
		md=(l+r)/2;
		if(ok(md))
			r=md;
		else
			l=md+1;
	}
	cout<<l<<endl;
	return 0;
}