#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define max_n 200000
#define INF 9223372036854775807ll
using namespace std;
const long long d[4][2]={{-1,0},{0,-1},{1,0},{0,1}};//delta
long long dp1[max_n+2][2][2];
long long dp2[max_n+2][2][2];
long long tp2[2][2];
int op[max_n+1];
#define gt(c) (c<'E'?(c<'B'?1:3):(c<'T'?2:0))
void read(int*op,int&n){
	int c;
	while(!isupper(c=getchar()));
	int*now=op;
	for(*++now=gt(c); isupper(c=getchar()); *++now=gt(c));
	n=now-op;
}
void mini(long long&x,long long y){
	y<x&&(x=y);
}
void test(){
	int n;
	read(op,n);
	memset(dp1[n+1],0,sizeof(dp1[n+1]));
	for(int i=n+1; --i; )
		(dp1[i][0][0]=dp1[i+1][0][0]+d[op[i]][0])>0&&(dp1[i][0][0]=0),
		(dp1[i][0][1]=dp1[i+1][0][1]+d[op[i]][0])<0&&(dp1[i][0][1]=0),
		(dp1[i][1][0]=dp1[i+1][1][0]+d[op[i]][1])>0&&(dp1[i][1][0]=0),
		(dp1[i][1][1]=dp1[i+1][1][1]+d[op[i]][1])<0&&(dp1[i][1][1]=0);
	memset(dp2[0],0,sizeof(dp2[0]));
	long long ans=INF;
	for(int i=0; ++i<=n; ){
		(dp2[i][0][0]=dp2[i-1][0][0]-d[op[i]][0])>0&&(dp2[i][0][0]=0),
		(dp2[i][0][1]=dp2[i-1][0][1]-d[op[i]][0])<0&&(dp2[i][0][1]=0),
		(dp2[i][1][0]=dp2[i-1][1][0]-d[op[i]][1])>0&&(dp2[i][1][0]=0),
		(dp2[i][1][1]=dp2[i-1][1][1]-d[op[i]][1])<0&&(dp2[i][1][1]=0);
		(tp2[0][0]=dp2[i][0][0]+d[op[i]][0])>0&&(tp2[0][0]=0),
		(tp2[0][1]=dp2[i][0][1]+d[op[i]][0])<0&&(tp2[0][1]=0),
		(tp2[1][0]=dp2[i][1][0]+d[op[i]][1])>0&&(tp2[1][0]=0),
		(tp2[1][1]=dp2[i][1][1]+d[op[i]][1])<0&&(tp2[1][1]=0);
		mini(ans,(max(tp2[0][1],dp1[i+1][0][1])-min(tp2[0][0],dp1[i+1][0][0])+1)*(max(tp2[1][1],dp1[i+1][1][1])-min(tp2[1][0],dp1[i+1][1][0])+1));
	}
	printf("%lld\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(++t; --t; test());
	return 0;
}