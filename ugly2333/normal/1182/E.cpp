//CF1182E
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
const int MO = 1e9+7;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y){
	int z=1;
	while(y){
		if(y&1)
			z=mul(z,x);
		y>>=1;
		x=mul(x,x);
	}
	return z;
}
int n=5;
struct node{
	int a[5][5];
	node(){
		memset(a,0,sizeof(a));
	}
}o,f,g;
int mo=MO-1;
int ad2(int&x,int y){
	x+=y;
	if(x>=mo)
		x-=mo;
}
int mul2(int x,int y){
	return (LL)x*y%mo;
}
node mul(node p,node q){
	node r;
	int i,j,k;
	for(i=0;i<n;i=i+1)
		for(j=0;j<n;j=j+1)
			for(k=0;k<n;k=k+1)
				ad2(r.a[i][k],mul2(p.a[i][j],q.a[j][k]));
	return r;
}
int main()
{
	LL m;
	int c,x,y,z,i,s;
	cin>>m>>x>>y>>z>>c;
	o.a[0][0]=1;
	o.a[0][1]=1,o.a[1][1]=1;
	o.a[3][2]=1;
	o.a[4][3]=1;
	o.a[1][4]=2,o.a[2][4]=1,o.a[3][4]=1,o.a[4][4]=1;
	f=o;
	for(i=0;i<n;i=i+1)
		g.a[i][i]=1;
	m--;
	while(m){
		if(m&1)
			g=mul(g,f);
		f=mul(f,f);
		m>>=1;
	}
	s=fpow(c,g.a[0][2]);
	s=mul(s,fpow(c,g.a[1][2]));
	s=mul(s,fpow(x,g.a[2][2]));
	s=mul(s,fpow(y,g.a[3][2]));
	s=mul(s,fpow(z,g.a[4][2]));
	cout<<s;
	return 0;
}