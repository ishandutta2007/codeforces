//CF1609G
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1<<18;
int n,m,q;
LL a[N],b[N],t[N],s[N],ss[N],wb[N];
LL p1[N],p2[N];
void ch(int k,LL db,int l,int r){
	t[k]+=db;
	s[k]+=db*(r-l+1);
	ss[k]+=db*(p1[r]-p1[l-1]);
	wb[k]+=db;
}
void pu(int k){
	t[k]=t[k<<1];
	s[k]=s[k<<1]+s[k<<1|1];
	ss[k]=ss[k<<1]+ss[k<<1|1];
}
void pd(int k,int l,int r,int h){
	if(wb[k]){
		ch(k<<1,wb[k],l,h);
		ch(k<<1|1,wb[k],h+1,r);
		wb[k]=0;
	}
}
void build(int k=1,int l=2,int r=m){
	if(l==r){
		t[k]=b[l];
		s[k]=b[l];
		ss[k]=b[l]*l;
		return;
	}
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	pu(k);
}
void modify(int L,int R,LL db,int k=1,int l=2,int r=m){
	if(L<=l&&r<=R){
		ch(k,db,l,r);
		return;
	}
	int h=l+r>>1;
	pd(k,l,r,h);
	if(L<=h)
		modify(L,R,db,k<<1,l,h);
	if(h<R)
		modify(L,R,db,k<<1|1,h+1,r);
	pu(k);
}
int query(LL x,int k=1,int l=2,int r=m){
	if(l==r){
		if(t[k]>x)
			return l-1;
		return l;
	}
	int h=l+r>>1;
	pd(k,l,r,h);
	if(x>=t[k<<1|1])
		return query(x,k<<1|1,h+1,r);
	return query(x,k<<1,l,h);
}
LL gs(int L,int R,int k=1,int l=2,int r=m){
	if(L<=l&&r<=R)
		return s[k];
	int h=l+r>>1;
	LL o=0;
	pd(k,l,r,h);
	if(L<=h)
		o+=gs(L,R,k<<1,l,h);
	if(h<R)
		o+=gs(L,R,k<<1|1,h+1,r);
	return o;
}
LL gss(int L,int R,int k=1,int l=2,int r=m){
	if(L<=l&&r<=R)
		return ss[k];
	int h=l+r>>1;
	LL o=0;
	pd(k,l,r,h);
	if(L<=h)
		o+=gss(L,R,k<<1,l,h);
	if(h<R)
		o+=gss(L,R,k<<1|1,h+1,r);
	return o;
}
int main()
{
	int i,x,y,z;
	LL ans,ls,lss,ns,nss;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(i=1;i<=m;i++)
		scanf("%lld",b+i);
	for(i=m;i>=2;i--)
		b[i]-=b[i-1];
	for(i=1;i<=m;i++){
		p1[i]=p1[i-1]+i;
		p2[i]=p2[i-1]+i*i;
	}
	build();
	while(q--){
		scanf("%d%d%d",&z,&x,&y);
		if(z==1){
			for(i=n-x+1;i<=n;i++)
				a[i]+=(LL)(i+x-n)*y;
		}
		else{
			if(x==m){
				x--;
				b[1]+=y;
			}
			modify(m-x+1,m,y);
		}
		ans=(LL)(a[1]+b[1])*(n+m-1);
		z=1;ls=0;lss=0;
		for(i=2;i<=n;i++){
			x=a[i]-a[i-1];
			y=query(x);//cout<<x<<' '<<y<<endl;
			if(z+1<=y){
ns=gs(2,y),nss=gss(2,y);
				ans+=(LL)(m+1+n-i+1)*(ns-ls);
				ans-=(nss-lss);
			
ls=ns,lss=nss;}
			ans+=(LL)(m-y+n-i+1)*x;
			z=y;
		}
		if(z<m){
			ans+=(LL)(m+1)*gs(z+1,m);
			ans-=gss(z+1,m);
		}
		printf("%lld\n",ans);
	}
	return 0;
}