#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define y1 wzpakking
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int mo1=1000000007;
const int mo2=1000000009;
const int M=10000000;
const int N=100005;
int P1[M],P2[M];
int hsh1[M],hsh2[M];
int ls[M],rs[M],nd;
void pushup(int k){
	P1[k]=1ll*P1[ls[k]]*(rs[k]?P1[rs[k]]:1)%mo1;
	P2[k]=1ll*P2[ls[k]]*(rs[k]?P2[rs[k]]:1)%mo2;
	hsh1[k]=(hsh1[rs[k]]+1ll*(rs[k]?P1[rs[k]]:1)*hsh1[ls[k]])%mo1;
	hsh2[k]=(hsh2[rs[k]]+1ll*(rs[k]?P2[rs[k]]:1)*hsh2[ls[k]])%mo2;
}
void insert(int &nk,int k,int l,int r,int p,int v){
	nk=++nd;
	ls[nk]=ls[k];
	rs[nk]=rs[k];
	if (l==r){
		hsh1[nk]=hsh2[nk]=v;
		P1[nk]=P2[nk]=10;
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[nk],ls[k],l,mid,p,v);
	else if (p>mid) insert(rs[nk],rs[k],mid+1,r,p,v);
	pushup(nk);
}
bool cmp(int k1,int k2,int l,int r){
	if (hsh1[k1]==hsh1[k2]&&hsh2[k1]==hsh2[k2]) return 0;
	if (l==r) return hsh1[k1]<hsh1[k2];
	int mid=(l+r)/2;
	if (hsh1[ls[k1]]!=hsh1[ls[k2]]||hsh2[ls[k1]]!=hsh2[ls[k2]])
		return cmp(ls[k1],ls[k2],l,mid);
	return cmp(rs[k1],rs[k2],mid+1,r);
}
bool operator <(const pii &a,const pii &b){
	if (a.se!=b.se)
		return a.se<b.se;
	return cmp(a.fi,b.fi,1,5*N);
}
struct edge{
	int to,next,id;
}e[N*2];
int head[N],tot;
int vis[N],n,m,q[10];
pii dis[N];
struct node{
	int x; pii v;
	bool operator <(const node &a)const{
		return !(v<a.v);
	}
};
priority_queue<node> Q;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,i); add(y,x,i);
	}
	For(i,1,n){
		vis[i]=0;
		dis[i]=pii(0,1<<30);
	}
	dis[1]=pii(0,0);
	Q.push((node){1,dis[1]});
	while (!Q.empty()){
		int x=Q.top().x; Q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		for (int i=head[x];i;i=e[i].next){
			int id=e[i].id; *q=0;
			int rt=dis[x].fi,l=dis[x].se;
			for (;id;q[++*q]=id%10,id/=10);
			if (dis[e[i].to].se<l+*q) continue;
			for (;*q;insert(rt,rt,1,5*N,++l,q[(*q)--]));
			if (pii(rt,l)<dis[e[i].to]){
				dis[e[i].to]=pii(rt,l);
				Q.push((node){e[i].to,dis[e[i].to]});
			}
		}
	}
	For(i,2,n)
		printf("%d\n",hsh1[dis[i].fi]);
}