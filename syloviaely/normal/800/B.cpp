#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct point{
	int x,y;
	void scan(){
		scanf("%d%d",&x,&y);
	}
}A[110000];
int n;
point operator - (point k1,point k2){
	return (point){k1.x-k2.x,k1.y-k2.y};
}
long long cross(point k1,point k2){
	return 1ll*k1.x*k2.y-1ll*k1.y*k2.x;
}
#define sqr(x) (1ll*(x)*(x))
double dis(point k1,point k2){
	return sqrt(sqr(k1.x-k2.x)+sqr(k1.y-k2.y));
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) A[i].scan();
	A[n+1]=A[1]; A[n+2]=A[2];
	double ans=1e20;
	for (int i=1;i<=n;i++)
		ans=min(ans,abs(cross(A[i+1]-A[i],A[i+2]-A[i]))/dis(A[i],A[i+2]));
	printf("%.11lf\n",ans/2);
	return 0;
}