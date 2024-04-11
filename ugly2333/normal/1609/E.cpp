//CF1609E
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
int n,q,a[N],b[N],c[N],ab[N],bc[N],abc[N];
char s[N],t[11];
void mrg(int k){
	a[k]=a[k<<1]+a[k<<1|1];
	b[k]=b[k<<1]+b[k<<1|1];
	c[k]=c[k<<1]+c[k<<1|1];
	ab[k]=min(min(a[k],b[k]),min(a[k<<1]+ab[k<<1|1],ab[k<<1]+b[k<<1|1]));
	bc[k]=min(min(b[k],c[k]),min(b[k<<1]+bc[k<<1|1],bc[k<<1]+c[k<<1|1]));
	abc[k]=min(min(min(min(a[k],b[k]),c[k]),min(ab[k],bc[k])),min(min(abc[k<<1]+c[k<<1|1],ab[k<<1]+bc[k<<1|1]),a[k<<1]+abc[k<<1|1]));
}
void st(int k,char x){
	a[k]=0,b[k]=0,c[k]=0;
	if(x=='a')
		a[k]=1;
	if(x=='b')
		b[k]=1;
	if(x=='c')
		c[k]=1;
}
void build(int k=1,int l=1,int r=n){
	if(l==r){
		st(k,s[l]);
		return;
	}
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	mrg(k);
}
void modify(int x,int k=1,int l=1,int r=n){
	if(l==r){
		st(k,s[l]);
		return;
	}
	int h=l+r>>1;
	if(x<=h)
		modify(x,k<<1,l,h);
	else
		modify(x,k<<1|1,h+1,r);
	mrg(k);
}
int main()
{
	int i;
	scanf("%d%d%s",&n,&q,s+1);
	build();
	while(q--){
		scanf("%d%s",&i,t);
		s[i]=t[0];
		modify(i);
		printf("%d\n",abc[1]);
	}
	return 0;
}