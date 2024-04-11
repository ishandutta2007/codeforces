#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200005

char s[N];
int n;

#define sz(p) ((p)?(p)->sz:0)
namespace SegT{
	struct node{
		int sz;
		node *son[2];
		
		node(){
			sz=0;
			son[0]=son[1]=0;
		}
	}t[N<<6];
	int _t;
	inline void ins(node *&p,int L,int R,int x){
		if(!p)
			p=t+(++_t);
		p->sz++;
		if(L==R)
			return;
		int mid=(L+R)>>1;
		if(x<=mid)
			ins(p->son[0],L,mid,x);
		else
			ins(p->son[1],mid+1,R,x);
	}
	inline node *mrg(node *x,node *y){
		if(!x||!y)
			return x?x:y;
		node *p=t+(++_t);
		p->son[0]=mrg(x->son[0],y->son[0]);
		p->son[1]=mrg(x->son[1],y->son[1]);
		p->sz=sz(p->son[0])+sz(p->son[1]);
		return p;
	}
	inline bool sch(node *p,int L,int R,int l,int r){
		if(!p||L>r||R<l)
			return 0;
		if(l<=L&&R<=r)
			return p->sz>0;
		int mid=(L+R)>>1;
		return sch(p->son[0],L,mid,l,r)||sch(p->son[1],mid+1,R,l,r);
	}
}

struct node{
	node *fa,*ch[26],*g;
	int len,pos;
	SegT::node *t;
	int f;
}t[N<<1],*lst=t;
int _t;
inline void ins(int pos,int c){
	node *u=lst;
	lst=t+(++_t);
	lst->len=u->len+1;
	lst->pos=pos;
	SegT::ins(lst->t,1,n,pos);
	for(;u&&!u->ch[c];u=u->fa)
		u->ch[c]=lst;
	if(!u){
		lst->fa=t;
		return;
	}
	node *v=u->ch[c];
	if(v->len==u->len+1){
		lst->fa=v;
		return;
	}
	node *vv=t+(++_t);
	vv->fa=v->fa;
	vv->pos=v->pos;
	for(int i=0;i<26;i++)
		vv->ch[i]=v->ch[i];
	vv->len=u->len+1;
	for(;u&&u->ch[c]==v;u=u->fa)
		u->ch[c]=vv;
	lst->fa=v->fa=vv;
}

int cnt[N<<1],p[N<<1];

int ans;

int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		ins(i,s[i]-'a');
	for(int i=1;i<=_t;i++)
		cnt[t[i].len]++;
	for(int i=1;i<=n;i++)
		cnt[i]+=cnt[i-1];
	for(int i=1;i<=_t;i++)
		p[cnt[t[i].len]--]=i;
	for(int i=_t;i;i--)
		t[p[i]].fa->t=SegT::mrg(t[p[i]].fa->t,t[p[i]].t);
	t->g=t;
	for(int i=1;i<=_t;i++)
		if(t[p[i]].fa->g==t||SegT::sch(t[p[i]].fa->g->t,1,n,t[p[i]].pos-t[p[i]].len+t[p[i]].fa->g->len,t[p[i]].pos-1)){
			t[p[i]].f=t[p[i]].fa->g->f+1;
			t[p[i]].g=t+p[i];
		}
		else{
			t[p[i]].f=t[p[i]].fa->g->f;
			t[p[i]].g=t[p[i]].fa->g;
		}
	for(int i=1;i<=_t;i++)
		ans=std::max(ans,t[i].f);
	printf("%d\n",ans);
}