#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define W 30

char buf[1<<23],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<23,stdin),p1==p2)?EOF:*p1++)
inline void rd(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}

int n,a[N];

std::unordered_map<int,int> id;

int f[N];
inline int fnd(int x){
	return f[x]?f[x]=fnd(f[x]):x;
}
std::pair<int,int> g[N];

struct node{
	int sz;
	node *ch[2];
}t[N*50],*rt[N];
int _t;
inline void ins(int o,int x,int d){
	if(!rt[o])
		rt[o]=t+(++_t);
	node *u=rt[o];
	u->sz++;
	for(int i=W-1;~i;i--){
		int c=(x>>i)&1;
		if(!u->ch[c])
			u->ch[c]=t+(++_t);
		u=u->ch[c];
		u->sz++;
	}
}
inline void mrg(node *&x,node *y){
	if(!x||!y)
		return x=x?x:y,void();
	x->sz+=y->sz;
	mrg(x->ch[0],y->ch[0]),mrg(x->ch[1],y->ch[1]);
}
inline std::pair<int,int> sch(int x,node *u,node *v){
	int res=0;
	for(int i=W-1;~i;i--){
		int c=(x>>i)&1;
		if(u->ch[c]&&u->ch[c]->sz>(v&&v->ch[c]?v->ch[c]->sz:0))
			u=u->ch[c],v=v?v->ch[c]:0;
		else
			u=u->ch[c^1],v=v?v->ch[c^1]:0,res|=1<<i;
	}
	return {res,fnd(id[x^res])};
}

ll ans;

int main(){
	rd(n);
	for(int i=1;i<=n;i++)
		rd(a[i]);
	std::sort(a+1,a+n+1),n=std::unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=n;i++)
		id[a[i]]=i;
	for(int i=1;i<=n;i++)
		ins(0,a[i],i),ins(i,a[i],i);
	while(1){
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(!f[i])
				cnt++,g[i]={1<<W,0};
		if(cnt==1)
			break;
		for(int i=1;i<=n;i++)
			g[fnd(i)]=std::min(g[fnd(i)],sch(a[i],rt[0],rt[fnd(i)]));
		for(int i=1;i<=n;i++)
			if(!f[i]){
				auto [x,j]=g[i];
				if(!f[j]){
					f[j]=i;
					mrg(rt[i],rt[j]);
					ans+=x;
				}
			}
	}
	printf("%lld\n",ans);
}