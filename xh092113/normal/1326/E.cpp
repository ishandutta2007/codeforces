#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define glc(u) u << 1
#define grc(u) (u << 1) | 1

const int N = 3e5;
const int TN = 4 * N;

namespace IO{
	In int read(){
		int s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(int x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);		
	}
}
using namespace IO;

int n;
int p[N+5],loc[N+5],q[N+5];
int ans[N+5];

struct SegTree{
	int maxn[TN+5],flag[TN+5];
	void pushup(int u){
		maxn[u] = max(maxn[glc(u)],maxn[grc(u)]);
	}
	void pushdown(int u,int l,int r){
		if(flag[u] == 0)return;
		int m = (l + r) >> 1;
		int lc = glc(u),rc = grc(u);
		maxn[lc] += flag[u];
		maxn[rc] += flag[u];
		flag[lc] += flag[u];
		flag[rc] += flag[u];
		flag[u] = 0;
	}
	void ud(int u,int l,int r,int ql,int qr,int x){
		if(l == ql && r == qr){
			maxn[u] += x;
			flag[u] += x;
			return;
		}
		pushdown(u,l,r);
		int m = (l + r) >> 1;
		if(qr <= m)ud(glc(u),l,m,ql,qr,x);
		else if(ql > m)ud(grc(u),m + 1,r,ql,qr,x);
		else ud(glc(u),l,m,ql,m,x),ud(grc(u),m + 1,r,m + 1,qr,x);
		pushup(u);
	}
	In bool check(){
		return maxn[1] <= 0;
	}
}T;

int main(){
//	freopen("CF1326E.in","r",stdin);
//	freopen("CF1326E.out","w",stdout);
	n = read();
	for(rg int i = 1;i <= n;i++)p[i] = read(),loc[p[i]] = i;
	for(rg int i = 1;i <= n;i++)q[i] = read();
	int A = n;
	ans[0] = n;
	for(rg int i = 1;i < n;i++){
		T.ud(1,1,n,1,q[i],-1);
		while(1){
//cout<<"i="<<i<<" A="<<A<<" maxn="<<T.maxn[1]<<endl;
			T.ud(1,1,n,1,loc[A],1);

//cout<<"i="<<i<<" A-1="<<A-1<<" maxn="<<T.maxn[1]<<endl;
			if(T.check())A--;
			else{
				T.ud(1,1,n,1,loc[A],-1);
				break;
			}
		}
		ans[i] = A;
	}
	for(rg int i = 0;i < n;i++){
		write(ans[i]),putchar(i == n - 1 ? '\n' : ' ');
	}
	return 0;
}