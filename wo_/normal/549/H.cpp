#include<cstdio>
#include<vector>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

typedef double Real;

const Real eps=1e-10,inf=1e10;

typedef vector<long long> Poly;

Poly mul(Poly p1,Poly p2){
	Poly res;
	for(int i=0;i<3;i++) res.push_back(0);
	long long a=p1[1],b=p1[2],c=p2[1],d=p2[2];
	res[0]=a*c;
	res[1]=a*d+b*c;
	res[2]=b*d;
	return res;
}

Real solve(Poly p){
	long long a=p[0],b=p[1],c=p[2];
//	if(abs(a)<eps&&abs(b)<eps){
	if(a==0&&b==0){
//		if(abs(c)<eps) return 0;
		if(c==0) return 0;
		else return inf;
	}
//	if(abs(a)<eps){
	if(a==0){
		return abs((Real)c/b);
	}
	if((Real)b*b-4.0*(Real)a*c<-0.01) return inf;
	Real t=sqrt(max((Real)0,(Real)b*b-4.0*(Real)a*c));
	Real r1=(-b+t)/(a*2);
	Real r2=(-b-t)/(a*2);
	return min(abs(r1),abs(r2));
}

int main(){
	long long a,b,c,d;
//	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	cin>>a>>b>>c>>d;
	Real ans=inf;
	for(int stat=0;stat<16;stat++){
		Poly p[4];
		for(int i=0;i<4;i++) for(int j=0;j<3;j++) p[i].push_back(0);
		p[0][2]=-a;
		p[1][2]=-b;
		p[2][2]=-c;
		p[3][2]=-d;
		for(int i=0;i<4;i++){
			int n=(stat>>i)&1;
			if(n==0) n=-1;
			p[i][1]=n;
		}
		Poly m1=mul(p[0],p[3]);
		Poly m2=mul(p[1],p[2]);
		Poly m;
		for(int i=0;i<3;i++) m.push_back(m1[i]-m2[i]);
		Real cur=solve(m);
		ans=min(ans,cur);
	}
	Real ans2=max(min(abs(a),abs(d)),min(abs(b),abs(c)));
	ans=min(ans,ans2);
	printf("%.12f\n",ans);
	return 0;
}