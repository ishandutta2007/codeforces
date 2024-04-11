#include <bits/stdc++.h>
using namespace std;
const int INF=2018061000;
int n,m,q,a[300005],b[300005],cnt[1000005];
struct node{
	int l,r,val,add;
} s[4000005];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].val=INF;s[k].add=0;
	if(l==r)	return;
    int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void pushdown(int k){
	if(s[k].add){
		s[k<<1].add+=s[k].add;
		s[k<<1|1].add+=s[k].add;
		s[k<<1].val+=s[k].add;
		s[k<<1|1].val+=s[k].add;
		s[k].add=0;
    }
}
void change(int k,int l,int r,int v){
    if(l<=s[k].l&&s[k].r<=r){
        s[k].val+=v;
		s[k].add+=v;
        return;
    }
    pushdown(k);
    int mid=(s[k].l+s[k].r)>>1;
    if(r<=mid)		change(k<<1,l,r,v);
    else if(l>mid)	change(k<<1|1,l,r,v);
    else			change(k<<1,l,mid,v),change(k<<1|1,mid+1,r,v);
    s[k].val=min(s[k<<1].val,s[k<<1|1].val);
}
int ask(int k){
    if(s[k].val>=0)		return -1;
    if(s[k].l==s[k].r)	return s[k].l;
    pushdown(k);
    int mid=(s[k].l+s[k].r)>>1;
    if(s[k<<1|1].val<0)		return ask(k<<1|1);
    else					return ask(k<<1);
}
int main(){
    scanf("%d%d",&n,&m);
    build(1,1,1000000);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
		if(cnt[a[i]]==1)	change(1,a[i],a[i],-INF);
        change(1,1,a[i],-1);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        change(1,1,b[i],1);
    }
    scanf("%d",&q);
    while(q--){
        int opt,i,x;
        scanf("%d%d%d",&opt,&i,&x);
        if(opt==1){
            change(1,1,a[i],1);
            cnt[a[i]]--;
			if(cnt[a[i]]==0)	change(1,a[i],a[i],INF);
            a[i]=x;
			change(1,1,a[i],-1);
			cnt[a[i]]++;
			if(cnt[a[i]]==1)	change(1,a[i],a[i],-INF);
        }
        else{
            change(1,1,b[i],-1);
            b[i]=x;
            change(1,1,b[i],1);
        }
        printf("%d\n",ask(1));
    }
    return 0;
}