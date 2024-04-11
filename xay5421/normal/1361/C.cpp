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
const int N=1050005;
int n,a[N],fa[N],go[N];VI G[N];
int rev(int x){
	return x&1?x+1:x-1;
}
int id(int x){
	if(x&1)return (x+1)/2;
	else return x/2;
}
int fd(int x){return fa[x]==x?x:fa[x]=fd(fa[x]);}
void mer(int k1,int k2){
	int k3=go[k1],k4=go[k2];
	go[k1]=k4,go[k4]=k1,go[k2]=k3,go[k3]=k2;
}
void sol(int b){
	int all=(1<<b)-1;
	rep(i,0,all)G[i].clear();
	rep(i,1,n*2)G[a[i]&all].PB(i),fa[i]=i,go[i]=rev(i);
	rep(i,0,all)if(SZ(G[i])&1)return;
	rep(i,0,all){
		for(int j=0;j<SZ(G[i]);j+=2){
			go[G[i][j]]=G[i][j+1];
			go[G[i][j+1]]=G[i][j];
			fa[fd(id(G[i][j]))]=fd(id(G[i][j+1]));
		}
	}
	rep(i,0,all)if(SZ(G[i])){
		int k1=G[i][0];
		rep(j,1,SZ(G[i])-1){
			if(fd(id(G[i][j]))!=fd(id(k1))){
				mer(G[i][j],k1);
				fa[fd(id(G[i][j]))]=fd(id(k1));
			}
		}
	}
	rep(i,1,n)if(fd(i)!=fd(1))return;
	pt(b,'\n');
	int k1=1;
	rep(i,1,n){
		pt(k1,' '),pt(k1=rev(k1),' ');
		k1=go[k1];
	}
	exit(0);
}
signed main(){
	rd(n);
	rep(i,1,n)rd(a[i*2-1]),rd(a[i*2]);
	per(i,20,0)sol(i);
	return 0;
}