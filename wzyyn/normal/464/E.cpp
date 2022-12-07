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
const int mo1=1000000007;
const int mo2=1000000009;
const int M=10000005;
const int N=100050;
struct edge{
	int to,next,v;
}e[N*2];
struct nodef{
	int ans1,ans2;
	int sum,len;
	nodef operator +(const nodef &a)const{
		return (nodef){(ans1+a.ans1)%mo1,(ans2+a.ans2)%mo2,
					   sum+(sum==len?a.sum:0),len+a.len};
	}
}t[M];
int n,m,tot,head[N];
int vis[N],dis[N];
int q[N],from[N];
int nd,rt,INF,S,T;
int ls[M],rs[M];
int P1[N],P2[N];
int power(int x,int y,int mo){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void build(int &k,int l,int r){
	k=++nd;
	if (l==r){
		P1[l]=power(2,l,mo1);
		P2[l]=power(2,l,mo2);
		t[k]=(nodef){0,0,0,1};
		return;
	}
	int mid=(l+r)/2;
	build(ls[k],l,mid);
	build(rs[k],mid+1,r);
	t[k]=t[ls[k]]+t[rs[k]];
}
int cmp(int x,int y,int l,int r){
	if (t[x].ans1==t[y].ans1&&t[x].ans2==t[y].ans2) return 0;
	if (l==r) return t[x].ans1<t[y].ans1?-1:1;
	int mid=(l+r)/2;
	int ans=cmp(rs[x],rs[y],mid+1,r);
	return ans?ans:cmp(ls[x],ls[y],l,mid);
}
nodef ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return ask(ls[k],l,mid,x,mid)+ask(rs[k],mid+1,r,mid+1,y);
}
void clear(int &k,int ok,int l,int r,int x,int y){
	int nk=++nd;
	if (l==x&&r==y) return k=ok,void(0);
	int mid=(l+r)/2;
	ls[nk]=ls[k]; rs[nk]=rs[k]; k=nk;
	if (y<=mid) clear(ls[k],ls[ok],l,mid,x,y);
	else if (x>mid) clear(rs[k],rs[ok],mid+1,r,x,y);
	else{
		clear(ls[k],ls[ok],l,mid,x,mid);
		clear(rs[k],rs[ok],mid+1,r,mid+1,y);
	}
	t[k]=t[ls[k]]+t[rs[k]];
}
void change(int &k,int l,int r,int p){
	int nk=++nd;
	if (l==r){
		assert(!t[k].ans1);
		t[nk]=(nodef){P1[p],P2[p],1,1};
		return k=nk,void(0);
	}
	int mid=(l+r)/2;
	ls[nk]=ls[k]; rs[nk]=rs[k]; k=nk;
	if (p<=mid) change(ls[k],l,mid,p);
	else change(rs[k],mid+1,r,p);
	t[k]=t[ls[k]]+t[rs[k]];
}
int cmp(int x,int y){
	return cmp(x,y,0,N-1);
}
int insert(int k,int v){
	nodef tmp=ask(k,0,N-1,v,N-1);
	///if (tmp.len)
	//cout<<"WZYYN!"<<' '<<tmp.sum<<endl;
	clear(k,rt,0,N-1,v,v+tmp.sum);
	//cout<<"NZYYW!"<<endl;
	change(k,0,N-1,v+tmp.sum);
	//cout<<"WZP!"<<endl;
	return k;
}
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
struct node{
	int x,rt;
	bool operator <(const node &a)const{
		int tmp=cmp(rt,a.rt);
		if (!tmp) return x<a.x;
		return tmp==1;
	}
};
priority_queue<node> Q;
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	scanf("%d%d",&S,&T);
	build(rt,0,N-1);
	//cout<<"WZYYN!"<<endl; 
	INF=insert(rt,N-1);
	//cout<<"WZYYN!"<<' '<<t[INF].ans1<<endl; 
	For(i,1,n) dis[i]=INF;
	dis[S]=rt; Q.push((node){S,dis[S]});
	while (!Q.empty()){
		int x=Q.top().x; Q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		//cout<<"EXTEND "<<x<<' '<<t[dis[x]].ans1<<endl;
		for (int i=head[x];i;i=e[i].next){
			int ndis=insert(dis[x],e[i].v);
			//cout<<t[ndis].ans1<<endl;
			if (cmp(ndis,dis[e[i].to])==-1){
				dis[e[i].to]=ndis;
				from[e[i].to]=x;
				Q.push((node){e[i].to,dis[e[i].to]});
			}
		}
	}
	if (cmp(INF,dis[T])==0)
		return puts("-1"),0;
	printf("%d\n",t[dis[T]].ans1);
	//q[++*q]=T;
	for (int i=T;i;i=from[i]) q[++*q]=i;
	reverse(q+1,q+*q+1);
	printf("%d\n",*q);
	For(i,1,*q) printf("%d ",q[i]);
}