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
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void wri(ll a){write(a); putchar(' ');}
inline void writeln(ll a){write(a); puts("");}
const int N=400005,M=10000000;
ll dq,sum[M],tree[M],ycl[N];
int sz[M],lson[M],rson[M];
int vis[N],a[N],b[N],father[N],rt[N],nodecnt;
inline void push_up(int nod){
	sum[nod]=sum[lson[nod]]+sum[rson[nod]];
	sz[nod]=sz[lson[nod]]+sz[rson[nod]];
	tree[nod]=tree[lson[nod]]+tree[rson[nod]]+sz[rson[nod]]*sum[lson[nod]];
}
void insert(int l,int r,int pos,int de,int &nod){
	if(!nod)nod=++nodecnt;
	if(l==r){
		tree[nod]=sum[nod]=de; sz[nod]=1; return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)insert(l,mid,pos,de,lson[nod]); else insert(mid+1,r,pos,de,rson[nod]);
	push_up(nod);
}
inline int merge(int a,int b){
	if(!a||!b)return a|b;
	lson[a]=merge(lson[a],lson[b]);
	rson[a]=merge(rson[a],rson[b]);
	if(!lson[a]&&!rson[a]){
		tree[a]+=tree[b]+sum[b]*sz[a]; sum[a]+=sum[b]; sz[a]+=sz[b]; 
	}else push_up(a);
	return a;
}
ll get(int nod){
	return tree[rt[nod]]+(nod-1)*sum[rt[nod]];
}
inline int getfather(int x){
	return father[x]==x?x:father[x]=getfather(father[x]);
}
void Merge(int a,int b){
	int x=getfather(a),y=getfather(b);
	father[y]=x;
	dq-=get(x); dq-=get(y);
	rt[x]=merge(rt[x],rt[y]);
	dq+=get(x);
}
int n;
signed main(){
	n=read();
	for(int i=1;i<N;i++)father[i]=i;
	for(int i=1;i<=n;i++){
		a[i]=read(); b[i]=read();
		ycl[i]=ycl[i-1]+(ll)a[i]*b[i];
		a[i]=getfather(a[i]); father[a[i]]=a[i]+1;
		insert(1,N-1,b[i],b[i],rt[a[i]]); 
	}
	for(int i=1;i<N;i++)father[i]=i;
	for(int i=1;i<=n;i++){
		dq+=get(a[i]); //cout<<a[i]<<endl;
		if(vis[a[i]+1]){
			Merge(a[i],a[i]+1);
		}
		if(vis[a[i]-1]){
			Merge(a[i]-1,a[i]);
		}
		vis[a[i]]=1;
		//cout<<dq<<" "<<a[i]<<" "<<ycl[i]<<" "<<get(2)<<" "<<tree[rt[2]]<<" "<<sz[lson[rt[3]]]<<endl;
		writeln(dq-ycl[i]);
	}
}
/*

*/