#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct point{
	int x,y;
	void scan(){
		scanf("%d%d",&x,&y);
	}
}A[110000],o;
#define sqr(x) (1ll*(x)*(x))
long double dis(point k1,point k2){
	return sqrt(sqr(k1.x-k2.x)+sqr(k1.y-k2.y));
}
int n,pd[110000];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) A[i].scan();
	int where=2;
	for (int i=3;i<=n;i++)
		if (1ll*(A[1].x-A[2].x)*(A[1].y-A[i].y)==1ll*(A[1].x-A[i].x)*(A[1].y-A[2].y)){
			pd[i]=1;
			if (dis(A[1],A[i])<dis(A[1],A[where])) where=i;
		}
	int where3=0;
	for (int i=3;i<=n;i++){
		if (pd[i]==0){
			if (where3==0) where3=i; else 
			if (dis(A[i],A[1])+dis(A[i],A[where])<dis(A[where3],A[1])+dis(A[where3],A[where])) where3=i;
		}
	}
	printf("%d %d %d\n",1,where,where3);
	return 0;
}