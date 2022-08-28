//CF524F
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
const int N = 2e6+16;
const int B = 233;
const int MO = 1e9+9;
string s,q;
int n,nn,a[N],b[N],t[N*4],p[N],h[N];
void build(int k=1,int l=0,int r=nn){
	if(l==r){
		t[k]=b[l];
		return;
	}
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	t[k]=min(t[k<<1],t[k<<1|1]);
}
int query(int L,int R,int k=1,int l=0,int r=nn){
	if(L<=l&&r<=R)
		return t[k];
	int h=l+r>>1,o=N;
	if(L<=h)
		o=min(o,query(L,R,k<<1,l,h));
	if(h<R)
		o=min(o,query(L,R,k<<1|1,h+1,r));
	return o;
}
int geth(int l,int r){
	l--;
	return (h[r]-(LL)h[l]*p[r-l]%MO+MO)%MO;
}
int f(int l1,int r1,int l2,int r2){
	if(geth(l1,r1)==geth(l2,r2))
		return 0;
	int x,y;
	while(l1<r1){
		x=l1+r1>>1;
		y=l2+r2>>1;
		if(geth(l1,x)==geth(l2,y))
			l1=x+1,l2=y+1;
		else
			r1=x,r2=y;
	}
	return a[l1]>a[l2];
}
int main()
{
	int i,x,o,e,bl,br;
	cin>>s;
	n=s.length();
	s=s+s;
	nn=n+n;
	p[0]=1;
	for(i=1;i<=nn;i=i+1){
		b[i]=b[i-1];
		if(s[i-1]=='(')
			a[i]=0,b[i]++;
		else
			a[i]=1,b[i]--;
		p[i]=(LL)p[i-1]*B%MO;
		h[i]=((LL)h[i-1]*B%MO+a[i])%MO;
	}
	bl=0,br=b[n];
	build();
	x=1,o=-query(0,n);
	for(i=2;i<=n;i=i+1){
		e=b[i-1]-query(i-1,i+n-1);
		if(o>e){
			o=e;
			x=i;
			continue;
		}
		if(e==o&&f(x,x+n-1,i,i+n-1))
			x=i;
	}
	bl+=o,br+=o;
	while(bl--){
		q+='(';
	}
	for(i=x;i<x+n;i=i+1)
		q+=s[i-1];
	while(br--){
		q+=')';
	}
	cout<<q;
	return 0;
}