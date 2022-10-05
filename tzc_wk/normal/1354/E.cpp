/*
Contest: Educational Codeforces Round 87
Problem: 1354E
Author: tzc_wk
Time: 2020.5.17
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),m=read(),n1=read(),n2=read(),n3=read();
vector<int> g[5505];
int pt[5505],comp=0;
vector<int> vs[5505][2];
inline void dfs(int x,int c){
	pt[x]=c;
	vs[comp][c].push_back(x);
	foreach(it,g[x]){
		if(pt[*it]==-1){
			dfs(*it,c^1);
		}
		else if(pt[*it]==c){
			puts("NO");
			exit(0);
		}
	}
}
bool can[5505][5505];
int pre[5505][5505];
int col[5505];
inline void dump(int x,int y){
	if(!x)	return;
	if(pre[x][y]==-1)	exit(1);
	foreach(it,vs[x][pre[x][y]]){
		col[*it]=2;
	}
	foreach(it,vs[x][pre[x][y]^1]){
		if(n1){
			col[*it]=1;
			n1--;
		}
		else{
			col[*it]=3;
		}
	}
	dump(x-1,y-vs[x][pre[x][y]].size());
}
signed main(){
	fz(i,1,m){
		int x=read(),y=read();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	fill1(pt);
	fz(i,1,n)	if(pt[i]==-1){
		comp++;
		dfs(i,0);
//		cout<<vs[i][0].size()<<" "<<vs[i][1].size()<<endl;
	}
	fill1(pre);
	can[0][0]=1;
	fz(i,1,comp){
		fz(j,0,n){
			if(j>=vs[i][0].size()&&can[i-1][j-vs[i][0].size()])	can[i][j]=1,pre[i][j]=0;
			if(j>=vs[i][1].size()&&can[i-1][j-vs[i][1].size()])	can[i][j]=1,pre[i][j]=1;
		}
	}
//	puts("-1");
	if(!can[comp][n2])	puts("NO");
	else{
		puts("YES");
		dump(comp,n2);
		fz(i,1,n)	cout<<col[i];
	}
	return 0;
}
/*
3 2
1 1 1
1 2
2 3

5 0
0 5 0

5 5
1 2 2
1 2
2 3
3 4
4 5
2 5

12 10
3 3 6
1 2
2 3
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
*/