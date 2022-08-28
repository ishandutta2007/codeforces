//CF 963E
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
const int MO = 1e9+7;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int AD(int& x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
	if(x<0)
		x+=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y=MO-2){
	if(!y)
		return 1;
	int z=fpow(x,y>>1);
	z=mul(z,z);
	if(y&1)
		return mul(z,x);
	return z;
}
int r,p[4],q[4],e[N][N];
int m,a[N][N][N],t[N];
int n,b[N][N],c[N],d[N];
int main()
{
	int i,j,k,x,y,z;
	cin>>r;
	x=0;
	for(i=0;i<4;i=i+1)
		cin>>p[i],x+=p[i];
	for(i=0;i<4;i=i+1)
		p[i]=mul(p[i],fpow(x)),q[i]=fpow(p[i]);
	for(i=-r;i<=r;i=i+1){
		x=0;
		for(j=-r;j<=r;j=j+1){
			if(i*i+j*j<=r*r){
				e[i+r][j+r]=1;
				if(!x){
					m++;
					a[i+r][j+r][m]=1;
				}
				x++;
			}
		}
	}
	for(j=0;j<=r+r;j=j+1){
		for(i=0;i<=r+r;i=i+1){
			if(!e[i][j])
				continue;
			for(k=0;k<=m;k=k+1)
				t[k]=a[i][j][k];
			for(z=0;z<3;z=z+1){
				x=i+dx[z],y=j+dy[z];
				if(x>=0&&y>=0&&e[x][y]){
					for(k=0;k<=m;k=k+1)
						AD(t[k],-mul(p[z],a[x][y][k]));
				}
			}
			AD(t[0],-1);
			//for(k=0;k<=m;k=k+1)
			//	cout<<t[k]<<' ';
			//cout<<i<<j<<endl<<endl;
			if(e[i][j+1]){
				for(k=0;k<=m;k=k+1)
					a[i][j+1][k]=mul(t[k],q[3]);
			}
			else{
				n++;
				for(k=0;k<=m;k=k+1)
					b[n][k]=t[k];
			}
		}
	}
	for(j=1;j<=m;j=j+1){
		for(i=1;i<=n;i=i+1)
			if(b[i][j]&&!c[i])
				break;
		if(i>n)
			continue;
		x=fpow(b[i][j]);
		for(k=0;k<=m;k=k+1)
			b[i][k]=mul(b[i][k],x);
		z=i;
		c[z]=j;
		for(i=1;i<=n;i=i+1){
			x=b[i][j];
			if(i==z||!x)
				continue;
			for(k=0;k<=m;k=k+1)
				AD(b[i][k],-mul(b[z][k],x));
		}
	}
	d[0]=1;
	for(i=1;i<=n;i=i+1)
		d[c[i]]=MO-b[i][0];
	x=0;
	for(k=0;k<=m;k=k+1)
		AD(x,mul(a[r][r][k],d[k]));
	cout<<x;
	return 0;
}