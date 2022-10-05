//Coded by tzc_wk
/*




D P 




 l l
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
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
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
int n=read(),a[200005];
vector<int> fac[200005],g[200005];
int _f[200005][10],_g[200005][10];
inline void dfs(int x,int fa){
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y==fa)	continue;
		dfs(y,x);
		for(int f1=0;f1<fac[x].size();f1++){
			for(int f2=0;f2<fac[y].size();f2++){
				int _x=fac[x][f1],_y=fac[y][f2];
//				cout<<"factor="<<_x<<endl;
				if(_x==_y){
					if(_f[x][f1]<_f[y][f2]+1)	_g[x][f1]=_f[x][f1],_f[x][f1]=_f[y][f2]+1;
					else if(_g[x][f1]<_f[y][f2]+1)	_g[x][f1]=_f[y][f2]+1;
				}
			}
		}
	}
}
signed main(){
	fz(i,1,n){
		a[i]=read();
		int tmp=a[i];
		for(int j=2;j*j<=tmp;j++){
			if(tmp%j==0){
				fac[i].push_back(j);
				while(tmp%j==0)	tmp/=j;
			}
		}
		if(tmp>1)	fac[i].push_back(tmp);
	}
	fz(i,1,n-1){
		int x=read(),y=read();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	int ans=0;
	fz(i,1,n){
		for(int j=0;j<fac[i].size();j++)	ans=max(ans,_f[i][j]+_g[i][j]+1);
	}
	print(ans);
	return 0;
}
/*
4
4 6 9 12
1 3
3 4
2 4
*/