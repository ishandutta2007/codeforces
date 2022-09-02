#include<cmath> 
#include<cstdio>
#include<algorithm>
const int N=12005;
struct line{
	double l,r,k,b;
	void move(int x){l+=x,r+=x,b-=k*x;}
	double f(double x){return k*x+b;}
	void add(double x,double y){k+=x,b+=y;}
}t[N];
int n,q,a,b,top,x[N];double y[N];
double get(){
	double now=1e100,res;
	for(int i=1;i<=top;++i){
		double x=-t[i].b/t[i].k;x=std::min(std::max(x,t[i].l),t[i].r);
		double y=t[i].f(x);if(std::fabs(y)<now)now=std::fabs(y),res=x;
	}
	return res;
}
int main(){
	scanf("%d%d%d%d",&n,&q,&a,&b);
	for(int i=1;i<=n;++i)scanf("%d",&x[i]);
	t[1]=(line){1,1.0*q,2,-2.0*x[1]},top=1;y[1]=get();
	for(int i=2;i<=n;++i){
		int k;
		for(k=1;k<=top;++k)if(t[k].r>y[i-1])break;
		top+=2;
		for(int j=top;j>=k+2;--j)t[j]=t[j-2];
		t[k].r=y[i-1],t[k+2].l=y[i-1];
		for(int j=1;j<=k;++j)t[j].move(a);
		for(int j=k+2;j<=top;++j)t[j].move(b);
		t[k+1]=(line){t[k].r,t[k+2].l,0,0};
		for(int j=1;j<=top;++j)t[j].add(2,-2*x[i]);
		while(t[top].l>q)--top;t[top].r=q;
		y[i]=get();
	}
	for(int i=n-1;i>=1;--i){
		if(y[i]<y[i+1]-b)y[i]=y[i+1]-b;else
		if(y[i]>y[i+1]-a)y[i]=y[i+1]-a;
	}
	double ans=0;
	for(int i=1;i<=n;++i)printf("%.9lf ",y[i]),ans+=(x[i]-y[i])*(x[i]-y[i]);
	printf("\n%.9lf\n",ans);
	return 0;
}