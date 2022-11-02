#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,q,a[N];
long long lazy[N<<2];
struct data{
    int maxval,minval;
	long long sum;
}tree[N<<2];
inline void cao(int nod,int x,int l,int r){
    tree[nod].maxval+=x; tree[nod].minval+=x; tree[nod].sum+=(long long)x*(r-l+1);
    return;
}
inline void p(int nod){
    tree[nod].maxval=max(tree[nod<<1].maxval,tree[nod<<1|1].maxval);
    tree[nod].minval=min(tree[nod<<1].minval,tree[nod<<1|1].minval);
    tree[nod].sum=tree[nod<<1].sum+tree[nod<<1|1].sum;
}
inline void pushdown(int p,int l,int r){
	if(!lazy[p])return; int mid=(l+r)>>1;
    lazy[p<<1]+=lazy[p]; lazy[(p<<1)+1]+=lazy[p]; cao(p<<1,lazy[p],l,mid); cao(p<<1|1,lazy[p],mid+1,r); lazy[p]=0; 
}
inline long long ask(int l,int r,int i,int j,int nod){int mid=(l+r)>>1;
    if (l==i&&j==r) return tree[nod].sum; pushdown(nod,l,r);
    if (j<=mid) return ask(l,mid,i,j,nod<<1);
    else if(i>mid) return ask(mid+1,r,i,j,nod<<1|1);
    return ask(l,mid,i,mid,nod<<1)+ask(mid+1,r,mid+1,j,nod<<1|1);
}
inline void insert(int l,int r,int i,int j,int s,int nod){int mid=(l+r)>>1;
    if(tree[nod].maxval<s)return;
    if(l==i&&r==j&&tree[nod].maxval/s==tree[nod].minval/s){
        lazy[nod]-=tree[nod].minval/s*s; cao(nod,-tree[nod].minval/s*s,l,r); return;
    }
    pushdown(nod,l,r);
    if(j<=mid)insert(l,mid,i,j,s,nod<<1); else
    if(i>mid)insert(mid+1,r,i,j,s,nod<<1|1); else{
        insert(l,mid,i,mid,s,nod<<1); insert(mid+1,r,mid+1,j,s,nod<<1|1);
    }
    p(nod);
}
inline void change(int l,int r,int i,int s,int nod){
	if(l==r){
		tree[nod].maxval=tree[nod].minval=tree[nod].sum=s; lazy[nod]=0; return;
	}
	int mid=(l+r)>>1; pushdown(nod,l,r);
	if(i<=mid)change(l,mid,i,s,nod<<1);
	else change(mid+1,r,i,s,nod<<1|1);
	p(nod);
}
inline void build(int l,int r,int nod){int mid=(l+r)>>1;
    if (l==r) {tree[nod].maxval=tree[nod].minval=tree[nod].sum=a[l]; return;} //cout<<l<<" "<<r<<endl;
    build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
    p(nod);
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    write(a); puts("");
}
inline int  read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())    if (ch == '-')  positive = 0;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    return positive ? x : -x;
}
char ch[10];
int main(){
    n=read(); q=read();
    for(int i=1;i<=n;i++)a[i]=read();
    build(1,n,1);
    while(q--){
    	int op=read(),ll=read(),rr=read();
    	if(op==1)writeln(ask(1,n,ll,rr,1));
    	else if(op==2) insert(1,n,ll,rr,read(),1);
    	else change(1,n,ll,rr,1);
	}
}