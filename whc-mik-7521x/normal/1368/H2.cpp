#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,q;
struct matrix{
    int k1,k2,k3,k4;
    void add1(){
        k1+=1,k2+=1;
    }
    void add2(){
        k3+=1,k4+=1;
    }
    void ope(){
        swap(k1,k4),swap(k2,k3);
    }
    matrix operator*(const matrix kk)const{
        matrix res;
        res.k1=min(k1+kk.k1,k3+kk.k2);
		res.k3=min(k1+kk.k3,k3+kk.k4);
		res.k2=min(k2+kk.k1,k4+kk.k2);
		res.k4=min(k2+kk.k3,k4+kk.k4);
        return res;
    }
};
struct SegmentTreeMatrix{
    matrix t1[N<<2],t2[N<<2];
    int tag1[N<<2],tag2[N<<2];
	int sa[N<<2],sb[N<<2];
    void pushup(int rt){
        t1[rt]=t1[rt<<1]*t1[rt<<1|1];
        t2[rt]=t2[rt<<1]*t2[rt<<1|1];
        sa[rt]=sa[rt<<1]+sa[rt<<1|1];
        sb[rt]=sb[rt<<1]+sb[rt<<1|1];
    }
    void add_tag(int rt,int tg1,int tg2,int l,int r){
        if(tg1)swap(t1[rt],t2[rt]),t1[rt].ope(),t2[rt].ope(),sa[rt]=r-l+1-sa[rt];
        if(tg2)swap(t1[rt],t2[rt]),sb[rt]=r-l+1-sb[rt];
        tag1[rt]^=tg1;
        tag2[rt]^=tg2;
    }
    void pushdown(int rt,int l,int r){
        int mid=(l+r)>>1;
        add_tag(rt<<1,tag1[rt],tag2[rt],l,mid);
        add_tag(rt<<1|1,tag1[rt],tag2[rt],mid+1,r);
        tag1[rt]=tag2[rt]=0;
    }
    void build(int rt,int l,int r,int a[],int b[],int tp){
        if(l==r){
			t1[rt].k3=t1[rt].k2=tp;
			t2[rt]=t1[rt];
			if(a[l])sa[rt]++;
			if(b[l])sb[rt]++;
			if(a[l]){
                t1[rt].add1(),
                t2[rt].add1();
            }
			else{
                t1[rt].add2(),
                t2[rt].add2();
            }
			if(b[l]){
                t1[rt].add1(),
                t2[rt].add2();
            }
			else{
                t1[rt].add2(),
                t2[rt].add1();
            }
			return;
        }
        int mid=(l+r)>>1;
        build(rt<<1,l,mid,a,b,tp);build(rt<<1|1,mid+1,r,a,b,tp);
        pushup(rt);
    }
    void upd(int rt,int l,int r,int L,int R,int d1,int d2){
        if(L<=l&&r<=R)return add_tag(rt,d1,d2,l,r);
        pushdown(rt,l,r);
        int mid=(l+r)>>1;
        if(L<=mid)upd(rt<<1,l,mid,L,R,d1,d2);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d1,d2);
        pushup(rt);
    }
}tr1,tr2;
void ope1(int l,int r){
    tr1.upd(1,1,n,l,r,1,0);
}
void ope2(int l,int r){
    tr1.upd(1,1,n,l,r,0,1);
}
void ope3(int l,int r){
    tr2.upd(1,1,m,l,r,1,0);
}
void ope4(int l,int r){
    tr2.upd(1,1,m,l,r,0,1);
}
int ask1(){
	return min(
        min(tr1.t1[1].k1+tr2.sa[1],tr1.t1[1].k2+m-tr2.sa[1])+tr2.sb[1],
        min(tr1.t1[1].k3+tr2.sa[1],tr1.t1[1].k4+m-tr2.sa[1])+m-tr2.sb[1]
    );
}
int ask2(){
	return min(
        min(tr2.t1[1].k1+tr1.sa[1],tr2.t1[1].k2+n-tr1.sa[1])+tr1.sb[1],
        min(tr2.t1[1].k3+tr1.sa[1],tr2.t1[1].k4+n-tr1.sa[1])+n-tr1.sb[1]
    );
}
template<typename T>inline void read(T &t){
    bool flag=1;
    char c=getchar();t=0;
    while(!isdigit(c)){
        if(c=='-')flag=0;
        c=getchar();
    }
    while(isdigit(c))t=(t<<3)+(t<<1)+c-48,c=getchar();
    if(!flag)t=~(t-1);
}
template<typename T,typename...Args>inline void read(T &t,Args &...args){read(t);read(args...);}
template<typename T> inline void wrt(T x)
{
    short st[105],tp=0;
    if(x<0) putchar('-'),x=-x;
    do st[++tp]=x%10,x/=10; while(x);
    while(tp) putchar('0'|st[tp--]);
}
int main(){
    read(n,m,q);
    int a1[N],a2[N],a3[N],a4[N];
    for(int i=1;i<=n;i++)a1[i]=getchar()=='B';
    getchar();
    for(int i=1;i<=n;i++)a2[i]=getchar()=='B';
    getchar();
    for(int i=1;i<=m;i++)a3[i]=getchar()=='B';
    getchar();
    for(int i=1;i<=m;i++)a4[i]=getchar()=='B';
    getchar();
    tr1.build(1,1,n,a1,a2,m);
    tr2.build(1,1,m,a3,a4,n);
    wrt(min(ask1(),ask2()));
    puts("");
    while(q--){
        char s;
        int l,r;
        s=getchar();
        read(l,r);
        if(s=='L')ope1(l,r);
        if(s=='R')ope2(l,r);
        if(s=='U')ope3(l,r);
        if(s=='D')ope4(l,r);
        wrt(min(ask1(),ask2()));
        puts("");
    }
    return  0;
}