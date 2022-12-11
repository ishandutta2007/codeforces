#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=8;
int n,m,qu;
long long a[N];
struct dat{
	int a[M];
	dat(){memset(a,0,sizeof(a));}
	dat operator+(const dat y)const{
		dat res;
		for(int i=1;i<=m+1;i++)res.a[i]=y.a[a[i]];
		return res;
	}
};
struct seg{
    struct node{
        int l,r,tag;
        dat val[2];
    };
    node s[N<<3];
    void pushup(int rt){
        s[rt].val[0]=s[rt<<1|1].val[0]+s[rt<<1].val[0];
        s[rt].val[1]=s[rt<<1|1].val[1]+s[rt<<1].val[1];
    }
    void pushdown(int rt){
        if(s[rt].tag){
            swap(s[rt<<1].val[0],s[rt<<1].val[1]);s[rt<<1].tag^=1;
            swap(s[rt<<1|1].val[0],s[rt<<1|1].val[1]);s[rt<<1|1].tag^=1;
            s[rt].tag=0;
        }
    }
    void add_tag(int rt){
        swap(s[rt].val[0],s[rt].val[1]),s[rt].tag^=1;
    }
    void build(int rt,int l,int r){
        s[rt].l=l;s[rt].r=r;
        if(l==r){
            for(int i=1;i<=m;i++)s[rt].val[a[l]].a[i]=s[rt].val[a[l]^1].a[i]=i+1;
            s[rt].val[a[l]].a[m+1]=1;
            s[rt].val[a[l]^1].a[m+1]=m+1;
            return;
        }
        int mid=(l+r)>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    void upd(int rt,int l,int r){
        if(l<=s[rt].l&&s[rt].r<=r)return add_tag(rt);
        pushdown(rt);
        int mid=(s[rt].l+s[rt].r)>>1;
        if(r<=mid)upd(rt<<1,l,r);
        else if(l>mid)upd(rt<<1|1,l,r);
        else upd(rt<<1,l,mid),upd(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    dat query(int rt,int l,int r){
        if(l<=s[rt].l&&s[rt].r<=r) return s[rt].val[0];
        pushdown(rt);
        int mid=(s[rt].l+s[rt].r)>>1;
        if(r<=mid)return query(rt<<1,l,r);
        else if(l>mid)return query(rt<<1|1,l,r);
        else return query(rt<<1|1,mid+1,r)+query(rt<<1,l,mid);
    }
}tr;
int main(){
	scanf("%d%d%d",&n,&m,&qu);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]=!(a[i]&1);
	tr.build(1,1,n);
	while(qu--){
		int op;
        scanf("%d",&op);
		if(op==1){
			int l,r;
            long long x;
            scanf("%d%d%lld",&l,&r,&x);
			if(x&1)tr.upd(1,l,r);
		}
        else{
			int l,r;
            scanf("%d%d",&l,&r);
            dat t=tr.query(1,l,r);
			printf("%d\n",1+(t.a[m+1]==1));
		}
	}
	return 0;
}