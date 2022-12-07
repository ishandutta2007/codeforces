#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int mo=1000000007;
const int N=100005;
int n,nd,a[N],b[N],c[N];
int rt[N],ls[N*2],rs[N*2];
int pr[N],su[N],q[N],pos[N];
int ans;
vector<int> vec[N];
struct node{
	int a[3][3];
}t[N*2];
node operator +(node a,node b){
	node c;
	c.a[0][0]=(a.a[0][0]+b.a[0][0])%mo;
	c.a[0][1]=(a.a[0][1]+b.a[0][1]+1ll*a.a[0][0]*b.a[1][1])%mo;
	c.a[0][2]=(a.a[0][2]+b.a[0][2]+1ll*a.a[0][0]*b.a[1][2]+1ll*a.a[0][1]*b.a[2][2])%mo;
	c.a[1][1]=(a.a[1][1]+b.a[1][1])%mo;
	c.a[1][2]=(a.a[1][2]+b.a[1][2]+1ll*a.a[1][1]*b.a[2][2])%mo;
	c.a[2][2]=(a.a[2][2]+b.a[2][2])%mo;
	return c;
}
int build(int l,int r){
	int k=++nd;
	if (l==r){
		t[k].a[0][0]=pr[q[l]];
		t[k].a[1][1]=1;
		t[k].a[2][2]=su[q[l]];
		return k;
	}
	int mid=(l+r)/2;
	ls[k]=build(l,mid);
	rs[k]=build(mid+1,r);
	t[k]=t[ls[k]]+t[rs[k]];
	return k;
}
void change(int k,int l,int r,int p,int id,int v){
	if (l==r){
		t[k].a[0][0]=pr[id]*v;
		t[k].a[1][1]=v;
		t[k].a[2][2]=su[id]*v;
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(ls[k],l,mid,p,id,v);
	else change(rs[k],mid+1,r,p,id,v);
	t[k]=t[ls[k]]+t[rs[k]];
}
void change(int p){
	for (;p<=n;p+=p&(-p)) c[p]++;
}
int ask(int p){
	int ans=0;
	for (;p;p-=p&(-p)) ans+=c[p];
	return ans;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	memcpy(b,a,sizeof(b));
	sort(b+1,b+n+1);
	For(i,1,n) a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	For(i,1,n) pr[i]=ask(a[i]),change(a[i]);
	memset(c,0,sizeof(c));
	Rep(i,n,1) su[i]=ask(a[i]),change(a[i]);
	For(i,1,n) vec[a[i]].PB(i);
	For(i,1,n) if (vec[i].size()){
		int sz=vec[i].size();
		For(j,1,sz) q[j]=vec[i][j-1],pos[q[j]]=j;
		rt[i]=build(1,sz);
		ans=(ans+t[rt[i]].a[0][2])%mo;
	}
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int tp,x;
		scanf("%d%d",&tp,&x);
		ans=(ans+mo-t[rt[a[x]]].a[0][2])%mo;
		change(rt[a[x]],1,vec[a[x]].size(),pos[x],x,tp-1);
		ans=(ans+t[rt[a[x]]].a[0][2])%mo;
		printf("%d\n",ans);
	}
}