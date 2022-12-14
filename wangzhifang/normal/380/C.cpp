#include <bits/stdc++.h>
#define max_n 1000000
#define lson now<<1
#define rson now<<1|1
using namespace std;
typedef const int& ci;
struct node{
	int sum,ans,mi,ma;
	node():sum(0),ans(0),mi(0),ma(0){}
	node operator+(const node &b)const{
		node c;
		c.sum=sum+b.sum,
		c.ans=ans+b.ans+min(ma,-b.mi),
		c.mi=min(mi,sum+b.mi),
		c.ma=max(b.ma,ma+b.sum);
		return c;
	}
};
node s[max_n<<2];
char str[max_n+1];
void build(ci l,ci r,ci now){
	if(l==r){
		if(str[l]=='(')
			s[now].sum=1,s[now].ma=1;
		else
			s[now].sum=-1,s[now].mi=-1;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,lson),build(mid+1,r,rson);
	s[now]=s[lson]+s[rson];
}
node query(ci l,ci r,ci now,ci lft,ci rgt){
	if(l>=lft&&r<=rgt)
		return s[now];
	int mid=(l+r)>>1;
	if(lft<=mid&&rgt>mid)
		return query(l,mid,lson,lft,rgt)+query(mid+1,r,rson,lft,rgt);
	else
		if(lft<=mid)
			return query(l,mid,lson,lft,rgt);
		else
			return query(mid+1,r,rson,lft,rgt);
}
int main(){
	int n,q,l,r;
	scanf("%s%d",str+1,&q);
	n=strlen(str+1),build(1,n,1);
	for(++q; --q; printf("%d\n",query(1,n,1,l,r).ans<<1))
		scanf("%d%d",&l,&r);
	return 0;
}