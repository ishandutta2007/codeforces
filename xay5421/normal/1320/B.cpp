#include<set>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005,P=998244853998244353LL;
int n,m,k,p[N],q[N],he,ta,dis[N],tot[N];bool pd[N];
struct ed{int nxt,to;}G[N<<1];int lnk[N],pp;
void ae(int k1,int k2){G[++pp]=(ed){lnk[k1],k2},lnk[k1]=pp;}
void bfs(int st){
	pd[st]=1,tot[st]=1;
	q[++ta]=st;
	while(he!=ta){
		int k1=q[++he];
		for(int i=lnk[k1];i;i=G[i].nxt)
			if(!pd[G[i].to]){
				pd[G[i].to]=1;
				dis[G[i].to]=dis[k1]+1;
				tot[G[i].to]=tot[k1];
				q[++ta]=G[i].to;
			}else if(dis[G[i].to]==dis[k1]+1){
				(tot[G[i].to]+=tot[k1])%=P;
			}
	}
}
signed main(){
	rd(n),rd(m);
	for(int i=1;i<=m;++i){
		int k1,k2;rd(k1),rd(k2);
		ae(k2,k1);
	}
	rd(k);
	for(int i=1;i<=k;++i)rd(p[i]);
	bfs(p[k]);
	int mn=0,mx=0;
	for(int i=1;i<k;++i){
		if(dis[p[i]]==dis[p[i+1]]+1){
			if(tot[p[i]]!=tot[p[i+1]]){
				++mx;
			}
		}else ++mn,++mx;
	}
	pt(mn,' '),pt(mx,'\n');
	return 0;
}