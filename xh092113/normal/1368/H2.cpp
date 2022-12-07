#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define glc(u) (u << 1)
#define grc(u) ((u << 1) | 1)

const int N = 1e5;
const int TN = N << 2;
const ll inf = 0x3f3f3f3f3f3f3f3f;

typedef pair<ll,ll> pll;

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

struct node{
	ll w[2][2];
	node(){memset(w,0,sizeof(w));}
	node(ll w00,ll w01,ll w10,ll w11){
		w[0][0] = w00;
		w[0][1] = w01;
		w[1][0] = w10;
		w[1][1] = w11;
	}
	In friend node operator + (node a,node b){
		node c;
		for(rg int i = 0;i <= 1;i++)
			for(rg int j = 0;j <= 1;j++)
				c.w[i][j] = min(a.w[i][0] + b.w[0][j],a.w[i][1] + b.w[1][j]);
		return c;
	}
}Mf[N+5][2][2],Mg[N+5][2][2];

//dynamic dp
struct SegTree{	
 	node cost[TN+5][2][2],temp[2][2];
	bool f1[TN+5],f2[TN+5];
In void print(int u){
cout<<"print: u="<<u<<endl;
for(rg int i = 0;i < 2;i++)
	for(rg int j = 0;j < 2;j++){
		cout<<"i="<<i<<" j="<<j<<" ";
		cout<<"w00="<<cost[u][i][j].w[0][0]<<" w01="<<cost[u][i][j].w[0][1]<<" w10="<<cost[u][i][j].w[1][0]<<" w11="<<cost[u][i][j].w[1][1]<<endl;
	}
}
	In void pushup(int u){
		for(rg int i = 0;i <= 1;i++)
			for(rg int j = 0;j <= 1;j++)
				cost[u][i][j] = cost[glc(u)][i][j] + cost[grc(u)][i][j];
	}
	In void modify(int u,bool f1,bool f2){
		for(rg int i = 0;i <= 1;i++)
			for(rg int j = 0;j <= 1;j++)
				temp[i][j] = cost[u][i^f1][j^f2];
		for(rg int i = 0;i <= 1;i++)
			for(rg int j = 0;j <= 1;j++)
				cost[u][i][j] = temp[i][j];
	}
	In void pushdown(int u){
		if(!f1[u] && !f2[u])return;
		int lc = glc(u),rc = grc(u);
		f1[lc] ^= f1[u]; f2[lc] ^= f2[u]; modify(lc,f1[u],f2[u]);
		f1[rc] ^= f1[u]; f2[rc] ^= f2[u]; modify(rc,f1[u],f2[u]);
		f1[u] = f2[u] = 0;
	}
	void build(int u,int l,int r,int opt){
		if(l > r)return;
		if(l == r){
			if(opt == 0){
				for(rg int i = 0;i < 2;i++)
					for(rg int j = 0;j < 2;j++)
						cost[u][i][j] = Mf[l][i][j];
			}
			else{
				for(rg int i = 0;i < 2;i++)
					for(rg int j = 0;j < 2;j++)
						cost[u][i][j] = Mg[l][i][j];
			}
//cout<<"build: u="<<u<<" l="<<l<<" r="<<r<<" opt="<<opt<<endl;
//print(u);
			return;
		}
		int m = (l + r) >> 1;
		build(glc(u),l,m,opt);
		build(grc(u),m + 1,r,opt);
		pushup(u);
//cout<<"build: u="<<u<<" l="<<l<<" r="<<r<<" opt="<<opt<<endl;
//print(u);
	}
	void ud(int u,int l,int r,int ql,int qr,int flag1,int flag2){
		if(l > r)return;
		if(l == ql && r == qr){
			f1[u] ^= flag1; f2[u] ^= flag2; modify(u,flag1,flag2);
//cout<<"ud: u="<<u<<" l="<<l<<" r="<<r<<" ql="<<ql<<" qr="<<qr<<" flag1="<<flag1<<" flag2="<<flag2<<endl;
//print(u);
			return;
		}
		int m = (l + r) >> 1;
		pushdown(u);
		if(qr <= m)ud(glc(u),l,m,ql,qr,flag1,flag2);
		else if(ql > m)ud(grc(u),m + 1,r,ql,qr,flag1,flag2);
		else ud(glc(u),l,m,ql,m,flag1,flag2),ud(grc(u),m + 1,r,m + 1,qr,flag1,flag2);
		pushup(u);
//cout<<"ud: u="<<u<<" l="<<l<<" r="<<r<<" ql="<<ql<<" qr="<<qr<<" flag1="<<flag1<<" flag2="<<flag2<<endl;
//print(u);
	}
	In node query(){
		return cost[1][0][0];
	}
}Tf,Tg;

//ordinary segtree
struct OrdSegTree{
	int sum[TN+5][2],flag[TN+5];
	In void pushup(int u){
		sum[u][0] = sum[glc(u)][0] + sum[grc(u)][0];
		sum[u][1] = sum[glc(u)][1] + sum[grc(u)][1];
	}
	In void pushdown(int u){
		if(!flag[u])return;
		int lc = glc(u),rc = grc(u);
		flag[lc] ^= 1; swap(sum[lc][0],sum[lc][1]);
		flag[rc] ^= 1; swap(sum[rc][0],sum[rc][1]);
		flag[u] = 0;
	}
	void build(int u,int l,int r,int b[]){
		if(l > r)return;
		if(l == r){
			if(b[l])sum[u][1]++; else sum[u][0]++;
			return;
		}
		int m = (l + r) >> 1;
		build(glc(u),l,m,b);
		build(grc(u),m + 1,r,b);
		pushup(u);
	}
	void ud(int u,int l,int r,int ql,int qr){
		if(l > r)return;
		if(ql == l && qr == r){
			flag[u] ^= 1;
			swap(sum[u][0],sum[u][1]);
			return;
		}
		int m = (l + r) >> 1;
		pushdown(u);
		if(qr <= m)ud(glc(u),l,m,ql,qr);
		else if(ql > m)ud(grc(u),m + 1,r,ql,qr);
		else ud(glc(u),l,m,ql,m), ud(grc(u),m + 1,r,m + 1,qr);
		pushup(u);
	}
	pll query(){
		return make_pair(sum[1][0],sum[1][1]);
	}
}Tu,Td,Tl,Tr;

ll n,m,q;
int l[N+5],r[N+5],u[N+5],d[N+5];
char s[N+5];

ll solve_f(){
//cout<<"solve_f: "<<endl;
	pll p = Tu.query();
//cout<<"first="<<p.first<<" second="<<p.second<<endl;
	ll f00 = p.second + (l[1] != 0) + (r[1] != 0);
	ll f01 = p.first + (l[1] != 1) + (r[1] != 1);
//cout<<"f00="<<f00<<" f01="<<f01<<endl;
	node tr = Tf.query();
//cout<<"tr="<<tr.w[0][0]<<" "<<tr.w[0][1]<<" "<<tr.w[1][0]<<" "<<tr.w[1][1]<<endl;
	pll q = Td.query();
//cout<<"first="<<q.first<<" second="<<q.second<<endl;
	if(n == 1){
		ll fn0 = f00 + q.second;
		ll fn1 = f01 + q.first;
//cout<<"fn0="<<fn0<<" fn1="<<fn1<<endl;
		return min(fn0,fn1);
	}
//cout<<"q.first="<<q.first<<" q.second="<<q.second<<endl;
	ll fn0 = min(f00 + tr.w[0][0],f01 + tr.w[1][0]) + q.second;
	ll fn1 = min(f00 + tr.w[0][1],f01 + tr.w[1][1]) + q.first;
//cout<<"fn0="<<fn0<<" fn1="<<fn1<<endl;
	return min(fn0,fn1);
}

ll solve_g(){
//cout<<"solve_g: "<<endl;
	pll p = Tl.query();
	ll g00 = p.second + (u[1] != 0) + (d[1] != 0);
	ll g01 = p.first + (u[1] != 1) + (d[1] != 1);
//cout<<"g00="<<g00<<" g01="<<g01<<endl;
	node tr = Tg.query();
//cout<<"tr="<<tr.w[0][0]<<" "<<tr.w[0][1]<<" "<<tr.w[1][0]<<" "<<tr.w[1][1]<<endl;
	pll q = Tr.query();
//cout<<"first="<<q.first<<" second="<<q.second<<endl;
	if(m == 1){
		ll gm0 = g00 + q.second;
		ll gm1 = g01 + q.first;
//cout<<"gm0="<<gm0<<" gm1="<<gm1<<endl;
		return min(gm0,gm1);
	}
	ll gm0 = min(g00 + tr.w[0][0],g01 + tr.w[1][0]) + q.second;
	ll gm1 = min(g00 + tr.w[0][1],g01 + tr.w[1][1]) + q.first;
//cout<<"gm0="<<gm0<<" gm1="<<gm1<<endl;
	return min(gm0,gm1);
}

In void solve(){
	ll ans = min(solve_f(),solve_g());
	write(ans),putchar('\n');	
}

int main(){
//n=1 or m=1!!!
//	freopen("CF1368H2.in","r",stdin);
//	freopen("CF1368H2.out","w",stdout);
	n = read(),m = read(),q = read();
	scanf("%s",s + 1); for(rg int i = 1;i <= n;i++)l[i] = (s[i] == 'B');
	scanf("%s",s + 1); for(rg int i = 1;i <= n;i++)r[i] = (s[i] == 'B');
	scanf("%s",s + 1); for(rg int i = 1;i <= m;i++)u[i] = (s[i] == 'B');
	scanf("%s",s + 1); for(rg int i = 1;i <= m;i++)d[i] = (s[i] == 'B');
	
	Tl.build(1,1,n,l);
	Tr.build(1,1,n,r);
	Tu.build(1,1,m,u);
	Td.build(1,1,m,d);
//cout<<"sks"<<endl;

//horizonal	
	for(rg int i = 2;i <= n;i++){
		for(rg int f1 = 0;f1 <= 1;f1++)
			for(rg int f2 = 0;f2 <= 1;f2++){
				Mf[i][f1][f2].w[0][0] = ((l[i]^f1) != 0) + ((r[i]^f2) != 0);
				Mf[i][f1][f2].w[0][1] = ((l[i]^f1) != 1) + ((r[i]^f2) != 1) + m;
				Mf[i][f1][f2].w[1][0] = ((l[i]^f1) != 0) + ((r[i]^f2) != 0) + m;
				Mf[i][f1][f2].w[1][1] = ((l[i]^f1) != 1) + ((r[i]^f2) != 1);
			}
	}
	if(n > 1)Tf.build(1,2,n,0);
//cout<<"rkk"<<endl;

//vertical	
	for(rg int i = 2;i <= m;i++){
		for(rg int f1 = 0;f1 <= 1;f1++)
			for(rg int f2 = 0;f2 <= 1;f2++){
				Mg[i][f1][f2].w[0][0] = ((u[i]^f1) != 0) + ((d[i]^f2) != 0);
				Mg[i][f1][f2].w[0][1] = ((u[i]^f1) != 1) + ((d[i]^f2) != 1) + n;
				Mg[i][f1][f2].w[1][0] = ((u[i]^f1) != 0) + ((d[i]^f2) != 0) + n;
				Mg[i][f1][f2].w[1][1] = ((u[i]^f1) != 1) + ((d[i]^f2) != 1);
			}
	}
	if(m > 1)Tg.build(1,2,m,1);
//cout<<"anju"<<endl;
	
	solve();
	while(q--){
		char ch = getchar();
		while(ch < 'A' || ch > 'Z')ch = getchar();
		int L = read(), R = read();
//cout<<"ch="<<ch<<" L="<<L<<" R="<<R<<endl;
		if(ch == 'L'){
			Tl.ud(1,1,n,L,R);
			if(L == 1)l[1] ^= 1, L++;
			if(L <= R)Tf.ud(1,2,n,L,R,1,0);
		}
		else if(ch == 'R'){
			Tr.ud(1,1,n,L,R);
			if(L == 1)r[1] ^= 1, L++;
			if(L <= R)Tf.ud(1,2,n,L,R,0,1);
		}
		else if(ch == 'U'){
			Tu.ud(1,1,m,L,R);
			if(L == 1)u[1] ^= 1, L++;
			if(L <= R)Tg.ud(1,2,m,L,R,1,0);
		}
		else{
			Td.ud(1,1,m,L,R);
			if(L == 1)d[1] ^= 1, L++;
			if(L <= R)Tg.ud(1,2,m,L,R,0,1);
		}
		solve();
	}
	
	return 0;
}