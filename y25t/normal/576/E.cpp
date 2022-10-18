#include<bits/stdc++.h>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define N 500005
#define K 55

int n,m,k,q;

pii E[N];
int col[N],lst[N];

int f[(N<<1)*K],sz[(N<<1)*K];
std::stack<pii> st;
inline int fnd(int x){
	return f[x]?fnd(f[x]):x;
}
inline void mrg(int x,int y){
	int fx=fnd(x),fy=fnd(y);
	if(sz[fx]>sz[fy])
		std::swap(fx,fy);
	st.push(mp(fx,fy));
	if(fx==fy)
		return;
	f[fx]=fy;
	sz[fy]+=sz[fx];
}
inline void udo(){
	pii x=st.top();
	st.pop();
	if(x.fir==x.sec)
		return;
	f[x.fir]=0;
	sz[x.sec]-=sz[x.fir];
}

#define num(x,y) (((x)-1)*2*n+(y))

std::vector<pii> t[N<<2];
inline void ins(int p,int L,int R,int l,int r,pii x){
	if(L>r||R<l)
		return;
	if(l<=L&&R<=r){
		t[p].push_back(x);
		return;
	}
	int mid=(L+R)>>1;
	ins(p<<1,L,mid,l,r,x);
	ins(p<<1|1,mid+1,R,l,r,x);
}
inline void dfs(int p,int L,int R){
	int cur=st.size();
	bool flg=0;
	for(auto x:t[p]){
		int u=E[x.fir].fir,v=E[x.fir].sec,c=x.sec?x.sec:col[x.fir];
		if(!c)
			continue;
		mrg(num(c,u),num(c,v+n));
		mrg(num(c,u+n),num(c,v));
		if(fnd(num(c,u))==fnd(num(c,u+n)))
			flg=1;
	}
	if(L==R){
		for(auto x:t[p])
			if(x.sec&&!flg)
				col[x.fir]=x.sec;
		puts(flg?"NO":"YES");
	}
	else{
		int mid=(L+R)>>1;
		dfs(p<<1,L,mid);
		dfs(p<<1|1,mid+1,R);
	}
	while(st.size()>cur)
		udo();
}

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&E[i].fir,&E[i].sec);
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ins(1,1,q,lst[x]+1,i-1,mp(x,0));
		ins(1,1,q,i,i,mp(x,y));
		lst[x]=i;
	}
	for(int i=1;i<=m;i++)
		ins(1,1,q,lst[i]+1,q,mp(i,0));
	for(int i=1;i<=num(k,n+n);i++)
		sz[i]=1;
	dfs(1,1,q);
}