//CF1117G
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
const int N = 1e6+16;
int n,q,a[N],b[N],l[N],r[N],m,e[N];
LL s[N];
vector<int> v[N];
LL t[N<<2],w[N<<2];
void ch(int k,int x,int o){
	w[k]+=x;
	t[k]+=(LL)x*o;
}
void pushd(int k,int o){
	if(!w[k])
		return;
	ch(k<<1,w[k],o-(o>>1));
	ch(k<<1|1,w[k],o>>1);
	w[k]=0;
}
void modify(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		ch(k,1,r-l+1);
		return;
	}
	pushd(k,r-l+1);
	int h=l+r>>1;
	if(L<=h)
		modify(L,R,k<<1,l,h);
	if(h<R)
		modify(L,R,k<<1|1,h+1,r);
	t[k]=t[k<<1]+t[k<<1|1];
}
LL query(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return t[k];
	pushd(k,r-l+1);
	int h=l+r>>1;
	LL o=0;
	if(L<=h)
		o+=query(L,R,k<<1,l,h);
	if(h<R)
		o+=query(L,R,k<<1|1,h+1,r);
	return o;
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i),b[a[i]]=i;
	for(i=1;i<=q;i=i+1)
		scanf("%d",l+i);
	for(i=1;i<=q;i=i+1)
		scanf("%d",r+i);
	
	for(i=1;i<=q;i=i+1)
		v[r[i]].push_back(i);
	memset(t,0,sizeof(t));
	memset(w,0,sizeof(w));
	b[n+1]=0;
	m=1;
	e[1]=n+1;
	for(i=1;i<=n;i=i+1){
		while(e[m]<a[i]){
			e[m--]=0;
		}
		modify(b[e[m]]+1,i);
		e[++m]=a[i];
		for(j=v[i].size();j--;)
			s[v[i][j]]+=query(l[v[i][j]],n);
	}
	
	for(i=1;i<=n;i=i+1)
		v[i].clear();
	for(i=1;i<=q;i=i+1)
		v[l[i]].push_back(i);
	memset(t,0,sizeof(t));
	memset(w,0,sizeof(w));
	b[n+1]=n+1;
	m=1;
	e[1]=n+1;
	for(i=n;i;i=i-1){
		while(e[m]<a[i]){
			e[m--]=0;
		}
		modify(i,b[e[m]]-1);
		e[++m]=a[i];
		for(j=v[i].size();j--;)
			s[v[i][j]]+=query(1,r[v[i][j]]);
	}
	for(i=1;i<=q;i=i+1)
		printf("%lld ",s[i]-(r[i]-l[i]+1));
	return 0;
}