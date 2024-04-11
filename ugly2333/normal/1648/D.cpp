//CF1648D
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
const int N = 555555;
const int B = 1<<20;
const LL inf = 1e18;
int n,m,qx[N],qy[N],qz[N];
LL a[N][4],f[N],g[N],c[N];
pair<int,int> q[N];
struct node{
	LL x,y,z;
	node(LL X=0,LL Y=0,LL Z=0){
		x=X,y=Y,z=Z;
	}
}t[B];
node operator+(node p,node q){
	return node(min(p.x,q.x),min(p.y,q.y),min(min(p.z,q.z),p.x+q.y));
}
void build(int k=1,int l=1,int r=n){
	if(l==r){
		t[k]=node(f[l],g[l],f[l]+g[l]);
		return;
	}
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	t[k]=t[k<<1]+t[k<<1|1];
}
node query(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return t[k];
	int h=l+r>>1;
	if(R<=h)
		return query(L,R,k<<1,l,h);
	if(h<L)
		return query(L,R,k<<1|1,h+1,r);
	return query(L,R,k<<1,l,h)+query(L,R,k<<1|1,h+1,r);
}
LL p[B];
void modify2(int s,LL x,int k=1,int l=1,int r=n){
	if(l==r){
		p[k]=x;
		return;
	}
	int h=l+r>>1;
	if(s<=h)
		modify2(s,x,k<<1,l,h);
	else
		modify2(s,x,k<<1|1,h+1,r);
	p[k]=min(p[k<<1],p[k<<1|1]);
}
LL query2(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return p[k];
	int h=l+r>>1;
	if(R<=h)
		return query2(L,R,k<<1,l,h);
	if(h<L)
		return query2(L,R,k<<1|1,h+1,r);
	return min(query2(L,R,k<<1,l,h),query2(L,R,k<<1|1,h+1,r));
}
int main()
{
	int i,j,x;
	LL ans=inf;
	node o;
	scanf("%d%d",&n,&m);
	for(j=1;j<=3;j++){
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			a[i][j]=a[i-1][j]+x;
		}
	}
	for(i=1;i<=n;i++){
		f[i]=a[i][1]-a[i-1][2];
		g[i]=a[n][3]-a[i-1][3]+a[i][2];
		f[i]=-f[i];
		g[i]=-g[i];
		modify2(i,f[i]);//cout<<f[i]<<' '<<g[i]<<endl;
	}
	build();
	for(i=0;i<=n;i++)
		c[i]=inf;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",qx+i,qy+i,qz+i);
		q[i]=make_pair(qy[i],i);
		c[qy[i]]=min(c[qy[i]],query2(qx[i],qy[i])+qz[i]);
		o=query(qx[i],qy[i]);
		ans=min(ans,o.z+qz[i]);//cout<<ans<<endl;
	}
	for(i=1;i<=n;i++)
		modify2(i,c[i]);
	sort(q+1,q+m+1);
	for(i=1;i<=m;i++){
		j=q[i].second;
		c[qy[j]]=min(c[qy[j]],query2(max(1,qx[j]-1),qy[j])+qz[j]);
		modify2(qy[j],c[qy[j]]);
	}
	for(i=1;i<=n;i++)
		f[i]=c[i-1];
	build();
	for(i=1;i<=m;i++){
		o=query(qx[i],qy[i]);
		ans=min(ans,o.z+qz[i]);//cout<<ans<<endl;
	}
	printf("%lld\n",-ans);
	return 0;
}