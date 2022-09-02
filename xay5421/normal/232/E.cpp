#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
static char ibuf[1<<20];
char *fis=ibuf,*fit=ibuf;
inline char getc(){return fis==fit&&(fit=(fis=ibuf)+fread(ibuf,1,1<<20,stdin),fis==fit)?EOF:*fis++;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getc()))f^=!(c^45);x=(c&15);while(isdigit(c=getc()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=505,MAXQ=600005;
int n,m,ans[MAXQ];
char s[N][N];
bitset<N>f[N][N],g[N][N];
void sol(int l,int r,const vector<vector<int> >&q){
	if(SZ(q)==0)return;
	assert(l<=r);
	vector<vector<int> >L,R;
	int mid=(l+r)>>1;
	auto dir=[&](int x,int y){
		return y<mid?-1:y==mid?0:1;
	};
	rep(i,1,n){
		f[i][mid].reset(),g[i][mid].reset();
		if(s[i][mid]=='.')f[i][mid].set(i),g[i][mid].set(i);
	}
	rep(i,2,n)if(s[i][mid]=='.')g[i][mid]|=g[i-1][mid];
	per(i,n-1,1)if(s[i][mid]=='.')f[i][mid]|=f[i+1][mid];
	per(j,mid-1,l){
		if(s[n][j]=='.')f[n][j]=f[n][j+1];
		else f[n][j].reset();
		per(i,n-1,1){
			if(s[i][j]=='.')f[i][j]=f[i+1][j]|f[i][j+1];
			else f[i][j].reset();
		}
	}
	rep(j,mid+1,r){
		if(s[1][j]=='.')g[1][j]=g[1][j-1];
		else g[1][j].reset();
		rep(i,2,n){
			if(s[i][j]=='.')g[i][j]=g[i-1][j]|g[i][j-1];
			else g[i][j].reset();
		}
	}
	for(auto k:q){
		int k1=dir(k[0],k[1]);
		int k2=dir(k[2],k[3]);
		if(!k1||!k2||(k1<0&&k2>0))
			ans[k[4]]=(f[k[0]][k[1]]&g[k[2]][k[3]]).any();
		else if(k1<0)L.PB(k);
		else R.PB(k);
	}
	sol(l,mid-1,L),sol(mid+1,r,R);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m);
	rep(i,1,n)rep(j,1,m){
		while(s[i][j]=getc(),s[i][j]!='.'&&s[i][j]!='#');
	}
	int Q;
	rd(Q);
	vector<vector<int> >q;
	rep(i,1,Q){
		int a,b,c,d;
		rd(a),rd(b),rd(c),rd(d);
		if(a>c||b>d)ans[i]=0;
		else q.PB({a,b,c,d,i});
	}
	sol(1,m,q);
	rep(i,1,Q)puts(ans[i]?"Yes":"No");
	return 0;
}