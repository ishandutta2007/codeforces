#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=100005;
int T,n,m,x,y,z,p;
int a[maxn],b[maxn];
int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&z,&p);
	z=4-z%4;
	for(int i=1;i<=p;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=p;i++){
		int u=a[i],v=b[i],uu,vv,nn=n,mm=m;
		for(int j=1;j<=x%4;j++)
			uu=v,vv=n-u+1,u=uu,v=vv,swap(n,m);
		if(y&1)
			v=m-v+1;
		for(int j=1;j<=z%4;j++)
			uu=v,vv=n-u+1,u=uu,v=vv,swap(n,m);
		printf("%d %d\n",u,v);
		n=nn,m=mm;
	}
	return 0;
}