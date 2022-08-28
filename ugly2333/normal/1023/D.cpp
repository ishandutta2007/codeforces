//CF 1023D
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
int n,q,a[N],l[N],r[N],T[N<<2];
void build(int k=1,int l=1,int r=n){
	if(l==r){
		T[k]=a[l];
		return;
	}
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	T[k]=min(T[k<<1],T[k<<1|1]);
}
int query(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return T[k];
	int h=l+r>>1,s=N;
	if(L<=h)
		s=min(s,query(L,R,k<<1,l,h));
	if(h<R)
		s=min(s,query(L,R,k<<1|1,h+1,r));
	return s;
}
int main()
{
	int i,x;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	x=0;
	for(i=1;i<=n;i=i+1)
		if(!a[i])
			x=i;
	for(i=1;i<n;i=i+1)
		if(a[i]&&!a[i+1])
			a[i+1]=a[i];
	for(i=n;i>1;i=i-1)
		if(a[i]&&!a[i-1])
			a[i-1]=a[i];
	if(!a[1]){
		cout<<"YES\n";
		for(i=1;i<=n;i=i+1)
			cout<<q<<' ';
		return 0;
	}
	for(i=1;i<=q;i=i+1)
		l[i]=N,r[i]=0;
	for(i=1;i<=n;i=i+1)
		l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i);
	if(!r[q]){
		if(!x){
			cout<<"NO";
			return 0;
		}
		a[x]=q;
	}
	for(i=1;i<=n;i=i+1)
		l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i);
	build();
	for(i=q;i;i=i-1){
		if(!r[i])
			continue;
		if(query(l[i],r[i])<i){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES\n";
	for(i=1;i<=n;i=i+1)
		cout<<a[i]<<' ';
	return 0;
}