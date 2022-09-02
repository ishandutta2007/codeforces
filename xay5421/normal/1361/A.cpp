#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=500005;
int n,m,t[N],id[N],col[N];VI G[N];bool vis[N];
signed main(){
	rd(n),rd(m);
	rep(i,1,m){
		int k1,k2;rd(k1),rd(k2);
		G[k1].PB(k2),G[k2].PB(k1);
	}
	rep(i,1,n)rd(t[i]);
	rep(i,1,n)id[i]=i;
	sort(id+1,id+1+n,[&](int x,int y){return t[x]<t[y];});
	rep(i,1,n){
		int k1=id[i];
		for(auto j:G[k1])
			if(col[j])vis[col[j]]=1;
		int x=1;
		while(vis[x])++x;
		col[k1]=x;
		if(col[k1]!=t[k1]){
			puts("-1");
			exit(0);
		}
		for(auto j:G[k1])if(col[j])vis[col[j]]=0;
	}
	rep(i,1,n)pt(id[i],i==n?'\n':' ');
	return 0;
}