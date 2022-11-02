#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=1000005,M=25000005;
pair<int,int> tree[M];
int n,nodecnt,lson[M],rson[M],dp[N];
vector<int> v[N];
void push_up(int nod){
	tree[nod]=max(tree[lson[nod]],tree[rson[nod]]);
}
void insert(int l,int r,int pos,int &nod){
	if(!nod)nod=++nodecnt;
	if(l==r){
		tree[nod].first++; tree[nod].second=-l; return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)insert(l,mid,pos,lson[nod]); else insert(mid+1,r,pos,rson[nod]);
	push_up(nod);
}
int merge(int a,int b){
	if(!a||!b)return a|b;
	lson[a]=merge(lson[a],lson[b]);
	rson[a]=merge(rson[a],rson[b]);
	if(lson[a]||rson[a])push_up(a); else tree[a].first+=tree[b].first;
	return a;
}
int dep[N],rt[N];
void dfs(int p,int fa){
	dep[p]=dep[fa]+1;
	insert(1,n,dep[p],rt[p]);
	for(unsigned i=0;i<v[p].size();i++)if(v[p][i]!=fa){
		dfs(v[p][i],p);
		rt[p]=merge(rt[p],rt[v[p][i]]);
	}
	//cout<<tree[rt[p]].first<<" "<<rt[p]<<endl;
	dp[p]=-tree[rt[p]].second-dep[p];
}
signed main(){
	n=read();
	for(int i=1;i<n;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)writeln(dp[i]);
}