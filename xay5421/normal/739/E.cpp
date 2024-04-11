#include<bits/stdc++.h>
using namespace std;
const int N=2005,T=40;
int n,a,b;double mid1,mid2,u[N],v[N];
struct data{
	double v;int a,b;
	bool operator<(const data&k2)const{return v<k2.v;}
	data operator+(const data&k2)const{return(data){v+k2.v,a+k2.a,b+k2.b};}
}f[N];
void jud(){
	f[0]=(data){0,0,0};
	for(int i=1;i<=n;++i){
		f[i]=f[i-1]+max({(data){0,0,0},(data){u[i]-mid1,1,0},(data){v[i]-mid2,0,1},(data){u[i]+v[i]-u[i]*v[i]-mid1-mid2,1,1}});
	}
}
void chk(){
	double l=0,r=1;
	for(int i=1;i<=T;++i){
		mid2=(l+r)/2.;
		jud();
		if(f[n].b>=b)l=mid2;
		else r=mid2;
	}
	mid2=l,jud();
}
int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;++i)scanf("%lf",&u[i]);
	for(int i=1;i<=n;++i)scanf("%lf",&v[i]);
	double l=0,r=1;
	for(int i=1;i<=T;++i){
		mid1=(l+r)/2.;
		chk();
		if(f[n].a>=a)l=mid1;
		else r=mid1;
	}
	mid1=l;
//	printf("%lf %lf\n",mid1,mid2);
	printf("%.5lf\n",f[n].v+mid1*a+mid2*b);
	return 0;
}