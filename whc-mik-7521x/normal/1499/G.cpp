#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10,mod=998244353;
int n1,n2,m,q,fa[N],en[N],val[N][2],vle[N],has;
bool tag[N];
void dec(int &x,int y){
    x=x>=y?x-y:x-y+mod;
}
void add(int &x,int y){
    x=x+y>=mod?x+y-mod:x+y;
}
int find(int x){
	if(fa[x]==x)return x;
	if(fa[fa[x]]==fa[x])return fa[x];
	int ret=find(fa[x]);
	tag[x]^=tag[fa[x]];
	return fa[x]=ret;
}
void unnion(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
    dec(has,val[x][tag[x]]);
    dec(has,val[y][tag[y]]);
	tag[x]^=tag[y],fa[x]=y;
    add(val[y][0],val[x][tag[x]]);
    add(val[y][1],val[x][!tag[x]]);
    add(has,val[y][tag[y]]);
}
void solve(int x){
	x=find(x);
    dec(has,val[x][tag[x]]);
	tag[x]^=1;
    add(has,val[x][tag[x]]);
}
bool is_red(int x){
	if(fa[x]==x)return tag[x];
	int fat=find(x);
	return tag[x]^tag[fat];
}
void add_edge(int x,int y,int rt){
	val[rt][1]=vle[rt];
	if(!en[x]&&!en[y]){solve(rt),en[x]=en[y]=rt;return;}
	else{
		if(!en[x])swap(x,y);
		if(!en[y]){
			if(!is_red(en[x]))solve(rt);
			unnion(en[x],rt);
			en[x]=0,en[y]=rt;
			return;
		}
		else{
			if(is_red(en[x])!=is_red(en[y]))solve(en[x]);
			if(!is_red(en[x]))solve(rt);
			unnion(en[x],rt),unnion(en[y],rt);
			en[x]=en[y]=0;
		}
	}
}
int main(){
	scanf("%d%d%d",&n1,&n2,&m);
    vle[0]=1;
    for(int i=1;i<N;i++)vle[i]=vle[i-1]*2%mod,fa[i]=i;
	for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y+n1,i);
    }
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
        int tp,x,y;
		scanf("%d",&tp);
		if(tp==1){
            scanf("%d%d",&x,&y);
            add_edge(x,y+n1,++m);
            printf("%d\n",has);
        }
		if(tp==2){
			int tot=0;
			for(int j=1;j<=m;j++)tot+=is_red(j);
			printf("%d ",tot);
			for(int j=1;j<=m;j++)if(is_red(j))printf("%d ",j);
            puts("");
		}
        fflush(stdout);
	}
	return 0;
}