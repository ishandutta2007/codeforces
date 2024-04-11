//CF1628C
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
const int N = 1111;
int n,a[N][N];
int solve(){
	int i,j,k,r=0,x=0,y;
	for(k=2;k<=n*2;k+=2){
		y=0;
		for(i=1;i<=n;i++){
			j=k-i;
			if(j>=1&&j<=n)
				y^=a[i][j],i++;
		}
		x^=y;
		r^=x;
	}
	return r;
}
int main()
{
	int T,i,j,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",a[i]+j);
		x=solve();
		for(i=1;i<=n;i++)
			reverse(a[i]+1,a[i]+n+1);
		printf("%d\n",x^solve());
	}
	return 0;
}