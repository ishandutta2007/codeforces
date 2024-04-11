#include<bits/stdc++.h>
using namespace std;
#define ls(x) t[x].ch[0]
#define rs(x) t[x].ch[1]
#define ll long long 
const ll mod = 998244353;
const int N = 1e6+9;
int T,n,m,tot;
struct pp{int x,y;}a[N];

struct fhq{int rnd,ch[2],tag,val,mx,siz;}t[N];
int New(int id){
	++tot;ls(tot)=rs(tot)=0;t[tot].val=id,t[tot].mx=id,t[tot].tag=0;
	t[tot].rnd=rand();t[tot].siz=1;return tot;
}


void pushup(int c){
	t[c].mx=max(t[c].val,max(t[ls(c)].mx,t[rs(c)].mx));
	t[c].siz=t[ls(c)].siz+t[rs(c)].siz+1;
	return ;
}

void upd(int c,int d){
	if(!c) return ;
	t[c].tag+=d;
	t[c].val+=d,t[c].mx+=d;
	return ;
}

void pushdown(int c){
    if(!t[c].tag) return ;
	upd(ls(c),t[c].tag);
	upd(rs(c),t[c].tag);
	t[c].tag=0;
    return ;
}

void split(int c,int k,int &x,int &y){
    if(!c){x=y=0;return ;}
    pushdown(c);
    
    if(t[c].val<=k){
        x=c;split(rs(c),k,rs(c),y);
    }
    else{
        y=c;split(ls(c),k,x,ls(c));
    }
	     
    pushup(c);
    return ;
}

int merge(int x,int y){
    if(!x||!y) return x+y;
    if(t[x].rnd<t[y].rnd){
        pushdown(x);
        rs(x)=merge(rs(x),y);
        pushup(x);return x;
    }
    else{
        pushdown(y);
        ls(y)=merge(x,ls(y));
        pushup(y);return y;
    }
}

int rt;

ll fac[N],inv[N];

ll C(int x,int y){
	if(x<0||y<0||y<x) return 0;
	return fac[y]*inv[x]%mod*inv[y-x]%mod;
}

int main(){
	srand(517);
	fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<=N-9;i++) fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<=N-9;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	for(int i=1;i<=N-9;i++) (inv[i]*=inv[i-1])%=mod;
	
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].x=i;
		}
		tot=0,rt=0;
		for(int i=1;i<=m;i++){
			int x,y,z;
			split(rt,a[i].y-1,x,y);
			upd(y,1);
			if(t[x].mx==a[i].y-1&&t[x].mx){
				split(x,a[i].y-2,x,z);
			}
			rt=merge(merge(x,New(a[i].y)),y);
		}
		int x,y,z;
		int k=t[rt].siz+1;
		ll ans=C(n,n*2-k);
		printf("%lld\n",ans);
	}
	return 0;
}