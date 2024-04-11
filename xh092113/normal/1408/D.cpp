#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define glc(u) (u << 1)
#define grc(u) ((u << 1) | 1)

const int N = 2000;
const int inf = 0x3f3f3f3f;

typedef pair<int,int> pii;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

int f[N+5];

struct SegTree{
	int maxn[4*N+5];
	In void pushup(int u){
		maxn[u] = max(maxn[glc(u)],maxn[grc(u)]);
	}
	void build(int u,int l,int r){
//cout<<"build: u="<<u<<" l="<<l<<" r="<<r<<endl;
		if(l == r){maxn[u] = f[l];return;}
		int m = (l + r) >> 1;
		build(glc(u),l,m);
		build(grc(u),m + 1,r);
		pushup(u);
	}
	void ud(int u,int l,int r,int pos,int x){
		if(l == r){maxn[u] = x;return;}
		int m = (l + r) >> 1;
		if(pos <= m)ud(glc(u),l,m,pos,x);
		else ud(grc(u),m + 1,r,pos,x);
		pushup(u);
	}
	int query(){
		return maxn[1];
	}
}T;

int cnt,n,m;
pii a[N+5],c[N+5];
struct inst{
	int pos,newf,t;
	inst(){}
	inst(int _pos,int _newf,int _t){pos = _pos,newf = _newf,t = _t;}
}I[N*N+5];
int instn;
deque<pii> q;

In bool cmp(inst a,inst b){
	return a.t < b.t;
}

int main(){
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);

	n = read();m = read();
	for(rg int i = 1;i <= n;i++)a[i].first = read(),a[i].second = read();
	for(rg int i = 1;i <= m;i++)c[i].first = read(),c[i].second = read();
	sort(c + 1,c + m + 1);
	for(rg int i = 1;i <= m;i++){
		if(!q.empty() && q.back().second <= c[i].second)q.pop_back();
		q.push_back(c[i]);
	}
	int cnt = 0;
	for(rg int i = 0;i < q.size();i++)c[++cnt] = q[i];
	m = cnt;
//cout<<"c[]:"<<endl;
//for(rg int i = 1;i <= m;i++)cout<<c[i].first<<" "<<c[i].second<<endl;

	c[m+1].second = -inf;
	for(rg int i = 1;i <= n;i++){
		f[i] = 0;
		for(rg int j = 1;j <= m;j++)if(c[j].first >= a[i].first){

			f[i] = max(f[i],c[j].second - a[i].second + 1);
			I[++instn] = inst(i,max(0,c[j+1].second - a[i].second + 1),c[j].first - a[i].first + 1);
		}
	}	
	if(!instn){puts("0");return 0;}
	sort(I + 1,I + instn + 1,cmp);
//cout<<"I[]:"<<endl;
//for(rg int i = 1;i <= instn;i++)cout<<I[i].pos<<" "<<I[i].newf<<" "<<I[i].t<<endl;
	T.build(1,1,n);
	
	int ans = T.query();
	int pos = 1;
	while(1){
		int curt = I[pos].t;
		while(pos <= instn && I[pos].t == curt){
			int u = I[pos].pos;
			int x = I[pos].newf;
//cout<<"n="<<n<<" u="<<u<<" x="<<x<<endl;
			T.ud(1,1,n,u,x);
			pos++;
		}
		ans = min(ans,curt + T.query());
		if(pos == instn + 1)break;
	}
	cout << ans << endl;
	
	return 0;
}