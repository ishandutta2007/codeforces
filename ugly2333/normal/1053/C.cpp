//CF1053C
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
const int N = 222222;
const int MO = 1e9+7;
int n,a[N],w[N];
LL t[N<<2],e[N<<2];
void build(int k=1,int l=1,int r=n){
	if(l==r){
		t[k]=w[l];
		e[k]=(LL)a[l]*w[l]%MO;
		return;
	}
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	t[k]=t[k<<1]+t[k<<1|1];
	e[k]=(e[k<<1]+e[k<<1|1])%MO;
}
void modify(int x,int y,int k=1,int l=1,int r=n){
	if(l==r){
		t[k]=w[x];
		e[k]=(LL)a[x]*w[x]%MO;
		return;
	}
	int h=l+r>>1;
	if(x<=h)
		modify(x,y,k<<1,l,h);
	else
		modify(x,y,k<<1|1,h+1,r);
	t[k]=t[k<<1]+t[k<<1|1];
	e[k]=(e[k<<1]+e[k<<1|1])%MO;
}
int query1(LL s,int k=1,int l=1,int r=n){
	if(l==r)
		return l;
	int h=l+r>>1;
	if(s<=t[k<<1]*2)
		return query1(s,k<<1,l,h);
	return query1(s-t[k<<1]*2,k<<1|1,h+1,r);
}
LL query2(int L,int R,int k=1,int l=1,int r=n){
	if(L>R)
		return 0;
	if(L<=l&&r<=R)
		return t[k];
	int h=l+r>>1;
	LL s=0;
	if(L<=h)
		s+=query2(L,R,k<<1,l,h);
	if(h<R)
		s+=query2(L,R,k<<1|1,h+1,r);
	return s;
}
LL query3(int L,int R,int k=1,int l=1,int r=n){
	if(L>R)
		return 0;
	if(L<=l&&r<=R)
		return e[k];
	int h=l+r>>1;
	LL s=0;
	if(L<=h)
		s+=query3(L,R,k<<1,l,h);
	if(h<R)
		s+=query3(L,R,k<<1|1,h+1,r);
	return s%MO;
}
int main()
{
	int i,q,x,y;
	LL s,r;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i),a[i]-=i;
	for(i=1;i<=n;i=i+1)
		scanf("%d",w+i);
	build();
	while(q--){
		scanf("%d%d",&x,&y);
		if(x<0){
			x=-x;
			w[x]=y;
			modify(x,y);
		}
		else{
			s=query2(1,x-1)*2+query2(x,y);
			i=query1(s);
			s=query3(i,y)-query2(i,y)%MO*a[i]%MO;
			r=query2(x,i)%MO*a[i]%MO-query3(x,i);
			cout<<(s+r+(LL)MO*10)%MO<<endl;
		}
	}
	return 0;
}