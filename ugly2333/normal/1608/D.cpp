//CF1608D
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
const int N = 111111;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y=MO-2){
	int z=1;
	while(y){
		if(y&1)
			z=mul(z,x);
		x=mul(x,x);
		y>>=1;
	}
	return z;
}
int fac(int o){
	int i,x=1;
	for(i=1;i<=o;i++)
		x=mul(x,i);
	return x;
}
int n,a[N],c[3][3],s;
char ch[5];
int go(char x){
	if(x=='W')
		return 1;
	if(x=='B')
		return 2;
	return 0;
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",ch);
		x=go(ch[0]),y=go(ch[1]);
		c[x][y]++;
	}
	x=c[1][0]+c[0][1]+c[2][0]+c[0][2]+c[0][0]*2;
	y=-c[1][1]+c[2][2]+c[2][0]+c[0][2]+c[0][0];
	if(x>=y&&y>=0)
		ad(s,mul(fac(x),fpow(mul(fac(y),fac(x-y)))));
	if(!c[1][1]&&!c[2][2]){
		ad(s,MO-fpow(2,c[0][0]));
		if(!c[1][2]&&!c[0][2]&&!c[1][0])
			s++;
		if(!c[2][1]&&!c[2][0]&&!c[0][1])
			s++;
	}
	printf("%d\n",s);
	return 0;
}