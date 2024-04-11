//CF 930C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
int n,m,a[N],l[N],r[N];
int T[N<<2];
void modify(int x,int y,int k=1,int l=1,int r=n){
	if(l==r){
		T[k]=y;
		return;
	}
	int h=(l+r)>>1;
	if(x<=h)
		modify(x,y,k<<1,l,h);
	else
		modify(x,y,k<<1|1,h+1,r);
	T[k]=max(T[k<<1],T[k<<1|1]);
}
int query(int R,int k=1,int l=1,int r=n){
	if(r<=R)
		return T[k];
	int h=(l+r)>>1,o;
	o=query(R,k<<1,l,h);
	if(h<R)
		o=max(o,query(R,k<<1|1,h+1,r));
	return o;
}
int main()
{
	int i,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",&x,&y);
		a[x]++,a[y+1]--;
	}
	a[0]=1;
	for(i=1;i<=m;i=i+1)
		a[i]+=a[i-1];
	memset(T,0,sizeof(T));
	for(i=1;i<=m;i=i+1){
		l[i]=1+query(a[i]);
		modify(a[i],l[i]);
	}
	memset(T,0,sizeof(T));
	reverse(a+1,a+m+1);
	for(i=1;i<=m;i=i+1){
		r[i]=1+query(a[i]);
		modify(a[i],r[i]);
	}
	reverse(r+1,r+m+1);
	x=0;
	for(i=1;i<=m;i=i+1)
		x=max(x,l[i]+r[i]);
	cout<<x-1;
	return 0;
}