#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define ls t[x].son[0]
#define rs t[x].son[1]
const int N=6e5+5;
int n,ans;
struct node{
	int son[2],fa,val,tag;
};
struct Splay{
	node t[N];
	int rt,tot,mx,stk[N];
	int find(int x){return t[t[x].fa].son[1]==x?1:0;}
	void unnion(int x,int fa,int flag){t[fa].son[flag]=x,t[x].fa=fa;}
	void pushdown(int x){
		if(!t[x].tag)return;
		if(ls){t[ls].val+=t[x].tag,t[ls].tag+=t[x].tag;}
		if(rs){t[rs].val+=t[x].tag,t[rs].tag+=t[x].tag;}
		t[x].tag=0;
	}
	int ne(int val,int fa){t[++tot].fa=fa,t[tot].val=val;return tot;}
	void build(){rt=ne(-INF,0);t[rt].son[1]=ne(INF,rt);}
	void rotate(int x){
		int fa=t[x].fa,grand=t[fa].fa;
		int flag1=find(x),flag2=find(fa);
		unnion(x,grand,flag2);
		unnion(t[x].son[flag1^1],fa,flag1);
		unnion(fa,x,flag1^1);
	}
	void splay(int x,int to){
		int tmp=x;mx=0;
		stk[++mx]=tmp;
		while(tmp)stk[++mx]=tmp=t[tmp].fa;
		while(mx)pushdown(stk[mx--]);
		for(int fa=t[x].fa;t[x].fa!=to;rotate(x),fa=t[x].fa){
			if(t[fa].fa!=to)find(x)==find(fa)?rotate(fa):rotate(x);}
		if(!to)rt=x;
	}
	void insert(int &x,int val,int fa){
		if(!x){++ans;x=ne(val,fa);splay(x,0);return;}
		pushdown(x);
		if(val<t[x].val)insert(ls,val,x);
		else insert(rs,val,x);
	}
	void clear(int x){
		splay(x,0);
		int l=ls,r=rs;
		while(t[l].son[1])l=t[l].son[1];
		while(t[r].son[0])r=t[r].son[0];
		splay(l,0);splay(r,l);
		t[r].son[0]=0;--ans;
	}
	int pre(int val){
		int x,res=0,newroot;
		x=newroot=rt;
		while(x){
			pushdown(x);
			if(t[x].val<val){res=x;x=rs;}
			else x=ls;
		}
		splay(newroot,0);
		return res;
	}
	int nxt(int val){
		int x,res=0,newroot;
		x=newroot=rt;
		while(x){
			pushdown(x);
			if(t[x].val>val){res=x;x=ls;}
			else x=rs;
		}
		splay(newroot,0);
		return res;
	}
	void ope(int l,int r){
		int u=nxt(l-1),v=pre(r);
		if(t[u].val>t[v].val)return;
		if(u==v)t[u].val++;
		else if(t[u].val<t[v].val){
			splay(u,0);splay(v,u);
			int rson=t[v].son[0];
			++t[u].val;++t[v].val,t[rson].val++;
			if(rson)++t[rson].tag;
		}
	}
};
Splay tr;
int main(){
	scanf("%d",&n);tr.build();
	tr.insert(tr.rt,0,0);ans=0;
	for(int i=1,l,r;i<=n;i++){
		scanf("%d%d",&l,&r);
		int x=tr.nxt(r-1);
		if(x&&x!=1&&x!=2)tr.clear(x);
		tr.ope(l,r);
		tr.insert(tr.rt,l,0);
	}
	printf("%d",ans);
	return 0;
}