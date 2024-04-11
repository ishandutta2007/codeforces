//CF274C
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
const int N = 111;
const DB eps = 1e-8;
const DB inf = 1e18;
int n,x[N],y[N],z[N];
int cc,c[N],dd,d[N];
DB ans,X,Y;
int f(int i,int j,int k){
	//cout<<i<<j<<k<<endl;
	return (y[i]-y[j])*(x[j]-x[k])-(y[j]-y[k])*(x[i]-x[j]);
}
DB g(int i,int j){
	return (DB)(y[i]-Y)*(X-x[j])-(DB)(Y-y[j])*(x[i]-X);
}
DB pw(DB o){
	return o*o;
}
void cal(int o){
	//printf("%.4lf %.4lf\n",X,Y);
	int i,j,k;
	if(X-eps<x[1]||x[n]<X+eps)
		return;
	for(k=2;k<=cc;k=k+1)
		if(x[c[k-1]]<X+eps&&X-eps<x[c[k]])
			break;
	Y+=eps;
	if(g(c[k-1],c[k])>-eps)
		return;
	Y-=eps;
	for(k=2;k<=dd;k=k+1)
		if(x[d[k-1]]<X+eps&&X-eps<x[d[k]])
			break;
	Y-=eps;
	if(g(d[k-1],d[k])<eps)
		return;
	Y+=eps;
	DB t=pw(X-x[o])+pw(Y-y[o]);
	for(i=1;i<=n;i=i+1)
		if(t-eps>pw(X-x[i])+pw(Y-y[i]))
			return;
	ans=max(ans,t);
}
int r(int i,int j,int k){
	return (x[j]-x[i])*(x[k]-x[i])+(y[j]-y[i])*(y[k]-y[i]);
}
void solve(int i,int j,int k){
	if(f(i,j,k)==0)
		return;
	if(r(i,j,k)<0||r(j,k,i)<0||r(k,i,j)<0)
		return;
	LL a1,b1,c1,a2,b2,c2,t;
	a1=2*(x[j]-x[i]),b1=2*(y[j]-y[i]),c1=z[j]-z[i];
	a2=2*(x[k]-x[i]),b2=2*(y[k]-y[i]),c2=z[k]-z[i];
	//cout<<a1<<b1<<c1<<endl;
	t=a1*b2-a2*b1;
	X=(DB)(c1*b2-c2*b1)/t;
	Y=(DB)(c1*a2-c2*a1)/(-t);
	cal(i);
}
int e[N];
int main()
{
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",x+i,y+i);
		z[i]=x[i]*x[i]+y[i]*y[i];
	}
	for(i=1;i<=n;i=i+1)
		for(j=i+1;j<=n;j=j+1)
			if(x[i]>x[j]||(x[i]==x[j]&&y[i]>y[j]))
				swap(x[i],x[j]),swap(y[i],y[j]),swap(z[i],z[j]);
	for(i=1;i<=n;i=i+1){
		while(cc>1&&f(c[cc-1],c[cc],i)<=0){
			c[cc--]=0;
		}
		c[++cc]=i;
		while(dd>1&&f(d[dd-1],d[dd],i)>=0){
			d[dd--]=0;
		}
		d[++dd]=i;
	}
	//cout<<cc<<dd<<endl;
	if(cc<=2&&dd<=2){
		cout<<-1;
		return 0;
	}
	for(i=1;i<=n;i=i+1)
		for(j=i+1;j<=n;j=j+1)
			for(k=j+1;k<=n;k=k+1)
				solve(i,j,k);
	if(ans<eps)
		cout<<-1;
	else
		printf("%.9lf",sqrt(ans));
	return 0;
}