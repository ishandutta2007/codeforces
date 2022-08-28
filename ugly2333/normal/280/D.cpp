//CF 280D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
const int K = 22;
const int inf = 1e9;
const int W = N*4;
void cmax(int& x,int y){
	if(x<y)
		x=y;
}
int n,k=21,w,a[N],T[N*5][K][4];
void mrg(int x,int y,int z){
	int i,j;
	for(i=0;i<=k;i=i+1)
		for(j=0;j<4;j=j+1)
			T[x][i][j]=-inf;
	for(i=0;i<=k;i=i+1)
		for(j=0;i+j<=k;j=j+1){
			cmax(T[x][i+j][0],T[y][i][0]+T[z][j][0]);
			cmax(T[x][i+j][1],T[y][i][1]+T[z][j][0]);
			cmax(T[x][i+j][2],T[y][i][0]+T[z][j][2]);
			cmax(T[x][i+j][3],T[y][i][1]+T[z][j][2]);
			if(i&&j){
				cmax(T[x][i+j-1][0],T[y][i][2]+T[z][j][1]);
				cmax(T[x][i+j-1][1],T[y][i][3]+T[z][j][1]);
				cmax(T[x][i+j-1][2],T[y][i][2]+T[z][j][3]);
				cmax(T[x][i+j-1][3],T[y][i][3]+T[z][j][3]);
			}
		}
	for(i=1;i<=k;i=i+1)
		for(j=0;j<4;j=j+1)
			cmax(T[x][i][j],T[x][i-1][j]);
}
void build(int o=1,int l=1,int r=n){
	if(l==r){
		int i,j;
		T[o][0][0]=0;
		for(j=1;j<4;j=j+1)
			T[o][0][j]=-inf;
		for(i=1;i<=k;i=i+1){
			T[o][i][0]=max(a[l],0);
			for(j=1;j<4;j=j+1)
				T[o][i][j]=a[l];
		}
		return;
	}
	int h=l+r>>1;
	build(o<<1,l,h);
	build(o<<1|1,h+1,r);
	mrg(o,o<<1,o<<1|1);
}
void modify(int x,int y,int o=1,int l=1,int r=n){
	if(l==r){
		int i,j;
		T[o][0][0]=0;
		for(j=1;j<4;j=j+1)
			T[o][0][j]=-inf;
		for(i=1;i<=k;i=i+1){
			T[o][i][0]=max(y,0);
			for(j=1;j<4;j=j+1)
				T[o][i][j]=y;
		}
		return;
	}
	int h=l+r>>1;
	if(x<=h)
		modify(x,y,o<<1,l,h);
	else
		modify(x,y,o<<1|1,h+1,r);
	mrg(o,o<<1,o<<1|1);
}
void query(int L,int R,int o=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		mrg(w+1,w,o);
		w++;
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		query(L,R,o<<1,l,h);
	if(h<R)
		query(L,R,o<<1|1,h+1,r);
}
int main()
{
	int m,i,x,y,z;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	build();
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&i,&x,&y);
		if(i){
			scanf("%d",&z);
			w=W;
			query(x,y);
			printf("%d\n",T[w][z][0]);
		}
		else
			modify(x,y);
	}
	return 0;
}