#include <cstdio>
#include <cstring>
#define max_n 100000
#define max_c max_n
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
struct node{
	int v,nxt;
	il node(){}
	il node(ci a,ci c):v(a),nxt(c){}
};
struct tree{
	int head[max_n+1],cnt;
	node edge[max_n<<1];
	il void build(){
		memset(head,0,sizeof(head)),cnt=0;
	}
	il void insert(ci u,ci v){
		push(u,v);
		push(v,u);
	}
	il void push(ci u,ci v){
		edge[++cnt]=node(v,head[u]);
		head[u]=cnt;
	}
};
tree g;
int hsn[max_n+1],c[max_n+1];
int dfs(ci u,ci p=0){
    int hsz=0,hsu=0,szu=1;
    for(int i=g.head[u],v; i; i=g.edge[i].nxt){
        if((v=g.edge[i].v)!=p){
            int tmp=dfs(v,u);
            szu+=tmp,tmp>hsz&&(hsu=v,hsz=tmp);
        }
    }
    hsn[u]=hsu;
    for(int*i=&g.head[u],v; *i; i=&g.edge[*i].nxt)
		while((v=g.edge[*i].v)==p||v==hsu)
			if(!(*i=g.edge[*i].nxt))
				return szu;
    return szu;
}
int ton[max_c+1],nowval;
long long nowans;
long long ans[max_n+1];
il void ins(ci u){
    int tmp=++ton[c[u]];
    tmp>nowval?(nowans=c[u],nowval=tmp):(tmp==nowval&&(nowans+=c[u]));
}
il void del(ci u){
    --ton[c[u]];
}
void cnt(int u){
    do{
        for(int i=g.head[u]; i; i=g.edge[i].nxt)
            cnt(g.edge[i].v);
        ins(u);
    }while((u=hsn[u]));
}
void decnt(int u){
    do{
        for(int i=g.head[u]; i; i=g.edge[i].nxt)
            decnt(g.edge[i].v);
        del(u);
    }while((u=hsn[u]));
}
int nn;
void dsu(ci u){
	if(hsn[u]){
        for(int i=g.head[u],v; i; i=g.edge[i].nxt){
            dsu(v=g.edge[i].v);
            decnt(v);
            nowans=nowval=0;
        }
        dsu(hsn[u]);
        for(int i=g.head[u]; i; i=g.edge[i].nxt)
            cnt(g.edge[i].v);
    }
    ins(u);
    ans[u]=nowans;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        scanf("%d",c+i);
    for(int i=n,a,b; --i; g.insert(a,b))
        scanf("%d%d",&a,&b);
    dfs(1);
    dsu(1);
    for(int i=1; i<=n; ++i)
        printf("%lld ",ans[i]);
    return 0;
}