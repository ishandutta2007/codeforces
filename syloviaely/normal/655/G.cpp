#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
struct point{
    double x,y;
    void scan(){
        scanf("%lf%lf",&x,&y);
    }
    double getw(){
        return atan2(y,x);
    }
}A[110000];
int n,K;
point operator + (point k1,point k2){
    return (point){k1.x+k2.x,k1.y+k2.y};
}
point operator - (point k1,point k2){
    return (point){k1.x-k2.x,k1.y-k2.y};
}
point operator * (point k1,double k2){
    return (point){k1.x*k2,k1.y*k2};
}
point turn(point k1,double k2){
    return (point){k1.x*cos(k2)+k1.y*sin(k2),-k1.x*sin(k2)+k1.y*cos(k2)};
}
#define sqr(x) ((x)*(x))
double L,R;
double dis(point k1,point k2){
    return sqrt(sqr(k1.x-k2.x)+sqr(k1.y-k2.y));
}
struct atom{
    double L,R;
}x[210000];
struct circle{
    point o;
    double r;
};
set<double>S;
int compare(atom k1,atom k2){
	return k1.L<k2.L||(k1.L==k2.L&&k1.R<k2.R);
}
const double pi=acos(-1);
int cross(circle k1,circle k2){
//	 cout<<dis(k1.o,k2.o)<<endl;
    k2.o=k2.o-k1.o; double k3=k2.o.getw();
    double a=k2.r,b=k1.r,c=dis((point){0,0},k2.o);
    if (c>k1.r+k2.r||k2.r-k1.r>=c) return 0;
    double k4=(b*b+c*c-a*a)/(2*b*c); k4=fabs(acos(k4));
    L=-k4+k3; R=k4+k3; 
    if (R-L>=pi){
    	double k1=L; L=R; R=k1+pi*2;
    }
    while (L>=0) L-=pi*2,R-=pi*2;
    while (L<-2*pi) L+=pi*2,R+=pi*2;
	return 2;
}
int check(double k1){
    circle o=(circle){(point){K,0},k1}; int len=0;
    for (int i=1;i<=n;i++){
        circle now=(circle){A[i],dis(A[i],(point){-K,0})};
        if (cross(o,now)==0) continue;
      //  cout<<"fa "<<i<<" "<<L<<" "<<R<<endl;
        x[++len]=(atom){L,R};
        x[++len]=(atom){L+pi*2,R+pi*2};
    }
    sort(x+1,x+len+1,compare);
    S.clear();
    for (int i=1;i<=len;i++){
    	set<double>::iterator k=S.lower_bound(x[i].L);
    	if (k!=S.end()&&(*k)<=x[i].R) return 1;
    	S.insert(x[i].R);
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&K);
    for (int i=1;i<=n;i++) A[i].scan();
    double l=0,r=K*2;
    for (int i=1;i<=40;i++){
        double mid=(l+r)/2;
        if (check(mid)) r=mid; else l=mid;
    }
    printf("%.11lf\n",(l+r)/2);
    return 0;
}