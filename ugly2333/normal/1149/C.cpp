//CF1149C
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
const int N = 222222;
const int inf = 1e9;
void cmax(int&x,int y){
	if(x<y)
		x=y;
}
struct node{
	int f[3][2][2];
	node(){
		for(int i=3;i--;)
			for(int j=2;j--;)
				for(int k=2;k--;)
					f[i][j][k]=-inf;
	}
}t[N<<2];
char c[N];
int n,q,a[N];
void upd(int x){
	int i,j,k,o;
	for(i=0;i<3;i=i+1)
		for(j=2;j--;)
			for(k=2;k--;){
				o=t[x].f[i][j][k];
				if(i!=2)
					cmax(t[x].f[2][j][k],o);
				if(j)
					cmax(t[x].f[i][0][k],o);
				if(k)
					cmax(t[x].f[i][j][0],o);
			}
}
void mrg(int x,int y,int z){
	int i,j,k,l;
	t[x]=node();
	for(i=3;i--;)
		for(j=2;j--;)
			for(k=2;k--;)
				cmax(t[x].f[i][j][0],t[y].f[i][j][k]),cmax(t[x].f[i][0][k],t[z].f[i][j][k]);
	i=0,l=0;
	for(j=2;j--;)
		for(k=2;k--;)
			cmax(t[x].f[0][j][k],t[y].f[i][j][1]+t[z].f[l][1][k]);
	i=1,l=1;
	for(j=2;j--;)
		for(k=2;k--;)
			cmax(t[x].f[1][j][k],t[y].f[i][j][1]+t[z].f[l][1][k]);
	i=0,l=1;
	for(j=2;j--;)
		for(k=2;k--;)
			cmax(t[x].f[2][j][k],t[y].f[i][j][1]+t[z].f[l][1][k]);
	i=0,l=2;
	for(j=2;j--;)
		for(k=2;k--;)
			cmax(t[x].f[2][j][k],t[y].f[i][j][1]+t[z].f[l][1][k]);
	i=2,l=1;
	for(j=2;j--;)
		for(k=2;k--;)
			cmax(t[x].f[2][j][k],t[y].f[i][j][1]+t[z].f[l][1][k]);
	upd(x);
}
void build(int k=1,int l=1,int r=n){
	if(l==r){
		t[k]=node();
		if(a[l]==1)
			t[k].f[1][1][1]=1,t[k].f[0][1][1]=-1;
		else
			t[k].f[0][1][1]=1,t[k].f[1][1][1]=-1;
		t[k].f[2][1][1]=1;
		upd(k);
		return;
	}
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	mrg(k,k<<1,k<<1|1);
}
void query(int p,int k=1,int l=1,int r=n){
	if(l==r){
		a[l]=-a[l];
		t[k]=node();
		if(a[l]==1)
			t[k].f[1][1][1]=1,t[k].f[0][1][1]=-1;
		else
			t[k].f[0][1][1]=1,t[k].f[1][1][1]=-1;
		t[k].f[2][1][1]=1;
		upd(k);
		return;
	}
	int h=l+r>>1;
	if(p<=h)
		query(p,k<<1,l,h);
	else
		query(p,k<<1|1,h+1,r);
	mrg(k,k<<1,k<<1|1);
}
int main()
{
	int i,x,y;
	scanf("%d%d%s",&n,&q,c+1);
	n=2*(n-1);
	for(i=1;i<=n;i=i+1){
		if(c[i]=='(')
			a[i]=1;
		else
			a[i]=-1;
	}
	build();
	cout<<t[1].f[2][0][0]<<endl;
	while(q--){
		scanf("%d%d",&x,&y);
		query(x),query(y);
		printf("%d\n",t[1].f[2][0][0]);
	}
	return 0;
}