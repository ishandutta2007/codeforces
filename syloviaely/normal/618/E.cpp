#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct point{
	double x,y;
};
const int N=310000;
const double pi=acos(-1);
point R[N<<2];
int t[N<<2];
int n,m;
point turn(point k1,int k2){
	double k3=k2/180.0*pi;
	return (point){k1.x*cos(k3)+k1.y*sin(k3),-k1.x*sin(k3)+k1.y*cos(k3)};
}
void change(int k1){
	t[k1]=(t[k1*2]+t[k1*2+1])%360;
	point a=turn(R[k1*2+1],t[k1*2]);
	R[k1].x=R[k1*2].x+a.x;
	R[k1].y=R[k1*2].y+a.y;
}
void buildtree(int k1,int k2,int k3){
	if (k2==k3){R[k1]=(point){1,0}; t[k1]=0; return;}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid);
	buildtree(k1*2+1,mid+1,k3);
	change(k1);
}
void change1(int k1,int k2,int k3,int k4,int k5){
	if (k2==k3){
		point a=(point){k5,0}; a=turn(a,t[k1]); //cout<<k5<<" "<<a.x<<" "<<a.y<<endl; 
		R[k1].x+=a.x; R[k1].y+=a.y;
		return;
	}
	int mid=k2+k3>>1;
	if (mid>=k4)change1(k1*2,k2,mid,k4,k5); else 
	change1(k1*2+1,mid+1,k3,k4,k5);
	change(k1);
}
void change2(int k1,int k2,int k3,int k4,int k5){
	if (k2==k3){
		t[k1]=(t[k1]+k5)%360; R[k1]=turn(R[k1],k5);
		return;
	}
	int mid=k2+k3>>1;
	if (mid>=k4) change2(k1*2,k2,mid,k4,k5); else 
	change2(k1*2+1,mid+1,k3,k4,k5);
//	cout<<k1<<" "<<k2<<" "<<k3<<" "<<R[k1].x<<" "<<R[k2].y<<endl;
	change(k1);
}
int main(){
	scanf("%d%d",&n,&m);
	buildtree(1,1,n);
	for (;m;m--){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
		if (k1==1) change1(1,1,n,k2,k3); else change2(1,1,n,k2,k3);
		printf("%.7lf %.7lf\n",R[1].x,R[1].y);
	}
	return 0;
}