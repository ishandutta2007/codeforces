//CF1662C
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
const int N = 222;
const int K = 11111;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int n,m,k,b[N][N],c[N][N][N];
void ins(int x,int y){
	ad(b[x+n][y+n],1);
	ad(b[y][y+n],MO-1);
}
void matmul(int x,int y,int z){
	int i,j,k;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				ad(c[x][i][j],mul(c[y][i][k],c[z][k][j]));
}
int main()
{
	int i,j,x,y,o;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
		b[i+n][i]=1,b[i][n+i]=1;
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		ins(x,y);
		ins(y,x);
	}
	n*=2;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			c[0][i][j]=b[i][j];
	o=15;
	for(i=1;i<=o;i++)
		matmul(i,i-1,i-1);
	o++;
	for(i=1;i<=n;i++)
		c[o][i][i]=1;
	for(i=0;i<=15;i++)
		if((k-1)&(1<<i))
			matmul(o+1,o,i),o++;
	/*for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			cout<<c[1][i][j]<<' ';
		cout<<endl;
	}*/
	for(i=1;i<=n/2;i++)
		ad(c[0][i][i+n/2],MO-1);
	matmul(o+1,o,0),o++;
	n/=2;
	x=0;
	for(i=1;i<=n;i++)
		ad(x,c[o][i+n][i+n]);
	printf("%d\n",x);
	return 0;
}