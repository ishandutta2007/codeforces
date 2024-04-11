#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long  LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define F first
#define S second
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
#include<string>
const int N=1005;
int n,m,k,sx,sy,tx,ty,l,r,bs[N*N*4],s1[4]={0,0,1,-1},s2[4]={1,-1,0,0};
bool vis[N][N][4];
pair<int,int> zz,zs,que[N*N*4];
char ch[N][N];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)scanf("\n%c",&ch[i][j]);
	}
	cin>>sx>>sy>>tx>>ty;
	que[r=1]=mp(sx,sy); for(int i=0;i<4;i++)vis[sx][sy][i]=1;
	while(l<r){
		zs=que[++l];
		if(zs==mp(tx,ty)){
			writeln(bs[l]); return 0;
		}
		for(int i=0;i<4;i++){
			zz=zs;
			for(int j=0;j<k;j++){
				zz.F+=s1[i]; zz.S+=s2[i];
				if(zz.F&&zz.S&&zz.F<=n&&zz.S<=m&&!vis[zz.F][zz.S][i]&&ch[zz.F][zz.S]=='.'){
					vis[zz.F][zz.S][i]=1;
					que[++r]=zz;
					bs[r]=bs[l]+1;
				}else break;
			}
		}
	}
	puts("-1");
}