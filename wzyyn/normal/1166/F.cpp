#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int M=10000005;
const int N=100005;
int n,m,Q,nd,fa[N];
map<pii,int> mp;
int ls[M],rs[M],rt[N];
void insert(int &k,int l,int r,int p){
	if (!k) k=++nd;
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[k],l,mid,p);
	else insert(rs[k],mid+1,r,p);
}
int merge(int x,int y){
	if (!x||!y) return x+y;
	ls[x]=merge(ls[x],ls[y]);
	rs[x]=merge(rs[x],rs[y]);
	return x;
}
int ask(int k,int l,int r,int p){
	if (!k) return 0;
	if (l==r) return 1;
	int mid=(l+r)/2;
	if (p<=mid) return ask(ls[k],l,mid,p);
	return ask(rs[k],mid+1,r,p);
}
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void add(int x,int y){
	//cout<<"ADD"<<' '<<x<<' '<<y<<endl;
	x=get(x); y=get(y);
	if (x!=y) fa[x]=y,rt[y]=merge(rt[y],rt[x]);
}
void add(int x,int y,int c){
	insert(rt[get(x)],1,n,y);
	insert(rt[get(y)],1,n,x);
	if (mp[pii(x,c)]) add(y,mp[pii(x,c)]);
	else mp[pii(x,c)]=y;
	if (mp[pii(y,c)]) add(x,mp[pii(y,c)]);
	else mp[pii(y,c)]=x;
}
int main(){
	scanf("%d%d%*d%d",&n,&m,&Q);
	For(i,1,n) fa[i]=i;
	For(i,1,m){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		add(x,y,c);
	}
	while (Q--){
		char s[5];
		int x,y,v;
		scanf("%s%d%d",s+1,&x,&y);
		if (s[1]=='?')
			puts(ask(rt[get(x)],1,n,y)||get(x)==get(y)?"Yes":"No");
		else{
			scanf("%d",&v);
			add(x,y,v);
		} 
	}
}