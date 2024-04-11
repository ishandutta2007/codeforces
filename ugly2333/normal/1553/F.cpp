//CF1553F
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
const int N = 333333;
int n,m=3e5;
LL t[3][N];
void ad(int k,int x,LL y){
	while(x<=m){
		t[k][x]+=y;
		x+=x&-x;
	}
}
LL qu(int k,int x){
	LL y=0;
	while(x){
		y+=t[k][x];
		x-=x&-x;
	}
	return y;
}
int main()
{
	int i,j,x;
	LL s=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		s+=(LL)x*(i-1)+qu(2,x);
		s+=qu(1,m);
		for(j=x;j<=m;j+=x){
			s-=(LL)(i-1-qu(0,j-1))*x;
		}
		printf("%lld ",s);
		ad(0,x,1);
		ad(1,x,x);
		for(j=x;j<=m;j+=x)
			ad(2,j,-x);
	}
	return 0;
}