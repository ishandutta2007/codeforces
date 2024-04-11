#include<bits/stdc++.h>

using namespace std;

const int N=(1<<21)|5;
int n,k,a[N],s[N];
pair<int,int> e[N];
int top;

const int M=20005;
struct edge{
	int from,to,next,f,v;
}E[M*10];
int head[M],tot=1;
int dis[M],vis[M],q[M*3];
int SS,S,T,from[M];
void add(int x,int y,int f,int v){
	E[++tot]=(edge){x,y,head[x],f,v};
	head[x]=tot;
	E[++tot]=(edge){y,x,head[y],0,-v};
	head[y]=tot;
}
bool bfs(){
	int h=0,t=1;
	for (int i=1;i<=T;i++)
		dis[i]=-(1<<30),vis[i]=0;
	dis[SS]=0; q[1]=SS;
	while (h!=t){
		int x=q[++h];
		vis[x]=0;
		for (int i=head[x];i;i=E[i].next)
			if (dis[E[i].to]<dis[x]+E[i].v&&E[i].f){
				dis[E[i].to]=dis[x]+E[i].v;
				from[E[i].to]=i;
				if (!vis[E[i].to]){
					vis[E[i].to]=1;
					q[++t]=E[i].to;
				}
			}
	}
	return dis[T]!=-(1<<30);
}
int del(){
	for (int i=from[T];i;i=from[E[i].from])
		E[i].f--,E[i^1].f++;
	return dis[T];
}
int bic(int x){
	int s=0;
	for (;x;x-=x&(-x)) s^=1;
	return s;
}
void solve(){
	for (int i=1;i<=top;i++){
		q[++*q]=e[i].first;
		q[++*q]=e[i].second;
	}
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	SS=*q+1,S=SS+1,T=S+1;
	for (int i=1;i<=*q;i++){
		if (bic(q[i])&1) add(S,i,1,0);
		else add(i,T,1,0);
	}
	add(SS,S,k,0);
	for (int i=1;i<=top;i++){
		int p1=lower_bound(q+1,q+*q+1,e[i].first)-q;
		int p2=lower_bound(q+1,q+*q+1,e[i].second)-q;
		if (bic(q[p1])&1);
		else swap(p1,p2);
		add(p1,p2,1,a[e[i].first]+a[e[i].second]);
	}
	int ans=0;
	for (;bfs();ans+=del());
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<1<<n;i++)
		scanf("%d",&a[i]);
	for (int i=0;i<1<<n;i++)
		for (int j=0;j<n;j++)
			if (!(i&(1<<j)))
				s[a[i]+a[i+(1<<j)]]++;
	for (int i=N-2;i>=0;i--) s[i]+=s[i+1];
	int lbound=(2*n-1)*(k-1)+1,p=N-1;
	for (;p&&s[p]<lbound;--p);
	int rem=min(s[p],lbound)-s[p+1];
	for (int i=0;i<1<<n;i++)
		for (int j=0;j<n;j++)
			if (!(i&(1<<j))){
				int val=a[i]+a[i+(1<<j)];
				if (val>p) e[++top]=make_pair(i,i+(1<<j));
				else if (val==p&&rem) e[++top]=make_pair(i,i+(1<<j)),--rem;
			}
	solve();
}