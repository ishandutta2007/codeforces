//CF1060H
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
const int N = 22;
int d,p,q;
int c[N][N],s[5555];
int a[N][N],b[N][N],f[N];
int fpow(int x,int y=p-2){
	if(!y)
		return 1;
	LL z=fpow(x,y>>1);
	z=z*z%p;
	if(y&1)
		z=z*x%p;
	return z;
}
int w;
void pr(int x,int y,int z=0){
	if(z)
		printf("+ %d %d %d\n",x,y,z);
	else
		printf("^ %d %d\n",x,y);
	/*if(z)
		s[z]=(s[x]+s[y])%p;
	else
		s[y]=fpow(s[x],d);
	w++;
	*/
}
void mul(int r,int x){
	//cout<<s[r]<<'*'<<x<<'='<<(LL)s[r]*x%p<<'=';
	int t=100,i;
	if(x%2==0)
		x+=p;
	pr(r,r,t);
	x--;
	for(i=2;x;i=i+i){
		if(x&i)
			pr(r,t,r),x-=i;
		pr(t,t,t);
	}
	//cout<<s[r]<<endl;
}
void go(int r){
	int t=10,i;
	mul(9,0);
	for(i=t;i<=t+d;i=i+1){
		pr(8,9,i);
		mul(i,i-t);
		pr(i,r,i);
		pr(i,i);
		mul(i,b[q][i-t]);
	}
	pr(9,9,r);
	for(i=t;i<=t+d;i=i+1)
		pr(r,i,r);
}
int main()
{
	int i,j,k,e,x;
	/*for(i=1;i<=5000;i=i+1)
		s[i]=1;
	s[1]=233;
	s[2]=2333;
	d=10;
	p=1e9+7;*/
	cin>>d>>p;
	for(i=0;i<N;i=i+1){
		c[i][0]=1;
		for(j=1;j<=i;j=j+1)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
	}
	for(i=0;i<=d;i=i+1){
		for(j=0;j<=d;j=j+1)
			a[i][j]=(LL)fpow(i,d-j)*c[d][j]%p;
		b[i][i]=1;
	}
	for(i=0;i<=d;i=i+1){
		for(j=0;j<=d;j=j+1)
			if(!f[j]&&a[j][i])
				break;
		e=j;
		f[e]=1;
		if(i==2)
			q=j;
		x=fpow(a[j][i]);
		for(k=0;k<=d;k=k+1){
			a[e][k]=(LL)a[e][k]*x%p;
			b[e][k]=(LL)b[e][k]*x%p;
		}
		for(j=0;j<=d;j=j+1){
			if(j==e||!a[j][i])
				continue;
			x=a[j][i];
			for(k=i;k<=d;k=k+1)
				a[j][k]=(a[j][k]-(LL)a[e][k]*x%p+p)%p;
			for(k=0;k<=d;k=k+1)
				b[j][k]=(b[j][k]-(LL)b[e][k]*x%p+p)%p;
		}
	}
	pr(1,2,3);
	go(1);
	go(2);
	go(3);
	mul(1,p-1);
	mul(2,p-1);
	pr(1,2,1);
	pr(1,3,1);
	mul(1,fpow(2));
	printf("f 1\n");
	//cout<<s[1]<<endl;
	//cout<<w<<endl;
	return 0;
}