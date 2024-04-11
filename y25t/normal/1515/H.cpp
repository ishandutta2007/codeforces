#include<cstdio>
#include<algorithm>
#define N 200005
#define W 20
#define U ((1<<W)-1)

int n,m;

#define sz(p) ((p)?(p)->sz:0)
#define o1(p) ((p)?(p)->o1:0)
#define o2(p) ((p)?(p)->o2:0)
struct node{
	node *son[2];
	int sz,r,o1,o2;
	bool lf;
	
	node(){
		son[0]=son[1]=0;
		sz=r=o1=o2=lf=0;
	}
	
	inline void upd(){
		if(lf)
			return;
		sz=sz(son[0])+sz(son[1]);
		o1=o1(son[0])|o1(son[1]);
		o2=o2(son[0])|o2(son[1]);
	}
	inline void rev(int v){
		r^=v;
		int t1=o1,t2=o2;
		o1=(t1&(U^v))|(t2&v);
		o2=(t2&(U^v))|(t1&v);
	}
	inline void pshd(int k){
		if((r>>k)&1)
			std::swap(son[0],son[1]);
		if(son[0])
			son[0]->rev(r);
		if(son[1])
			son[1]->rev(r);
		r=0;
	}
}t[N*W*3],*rt=t;
int _t;
inline node *cpy(node *p){
	t[++_t]=*p;
	return &t[_t];
}
inline void ins(node *&p,int k,int v){
	if(!p)
		p=&t[++_t];
	if(k<0){
		p->sz=1;
		p->o1=v;
		p->o2=U^v;
		p->lf=1;
		return;
	}
	if(!((v>>k)&1))
		ins(p->son[0],k-1,v);
	else
		ins(p->son[1],k-1,v);
	p->upd();
}
inline void splt(node *p,int k,int v,node *&x,node *&y){
	if(k<0){
		x=0,y=p;
		return;
	}
	if(!p){
		x=y=0;
		return;
	}
	p->pshd(k);
	if(!((v>>k)&1)){
		y=p;
		x=cpy(p);
		x->son[1]=0;
		splt(p->son[0],k-1,v,x->son[0],y->son[0]);
	}
	else{
		x=p;
		y=cpy(p);
		y->son[0]=0;
		splt(p->son[1],k-1,v,x->son[1],y->son[1]);
	}
	x->upd();
	y->upd();
}
inline node *mrg(node *x,node *y,int k){
	if(!x||!y)
		return x?x:y;
	x->pshd(k);
	y->pshd(k);
	x->son[0]=mrg(x->son[0],y->son[0],k-1);
	x->son[1]=mrg(x->son[1],y->son[1],k-1);
	x->upd();
	return x;
}
inline void chgxor(node *&x,int k,int v){
	if(!x)
		return;
	x->rev(v);
}
inline void chgor(node *&x,int k,int v){
	if(!x)
		return;
	if(k<0)
		return;
	int tmp=v&x->o2;
	if(!(tmp&x->o1)){
		chgxor(x,k,tmp);
		return;
	}
	x->pshd(k);
	if(!((v>>k)&1)){
		chgor(x->son[0],k-1,v);
		chgor(x->son[1],k-1,v);
	}
	else{
		chgxor(x->son[0],k-1,1<<k);
		x->son[1]=mrg(x->son[0],x->son[1],k-1);
		x->son[0]=0;
		chgor(x->son[1],k-1,v);
	}
	x->upd();
}
inline void chgand(node *&x,int k,int v){
	chgxor(x,k,U);
	chgor(x,k,v^U);
	chgxor(x,k,U);
}
node *x,*y,*z;

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int v;
		scanf("%d",&v);
		ins(rt,W-1,v);
	}
	while(m--){
		int opt,l,r,v;
		scanf("%d%d%d",&opt,&l,&r);
		if(opt!=4)
			scanf("%d",&v);
		splt(rt,W-1,l,x,y);
		if(r<U)
			splt(y,W-1,r+1,y,z);
		else
			z=0;
		if(opt==1)
			chgand(y,W-1,v);
		if(opt==2)
			chgor(y,W-1,v);
		if(opt==3)
			chgxor(y,W-1,v);
		if(opt==4)
			printf("%d\n",y->sz);
		rt=mrg(x,mrg(y,z,W-1),W-1);
	}
}