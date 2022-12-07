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
const int N=2005;
const int mo=1000000007;
int n,K,L,ans;
int x[N],y[N],v[N];
int qx[N],qy[N],py[N];

vector<pii> op[N];
pii opp[N];
int pl[N],pr[N],q[N];
struct node{
	int X,Y,v;
}opt[N*4];
int mx[N*4],smx[N*4];
int mxs[N*4],sum[N*4];
void build(int k,int l,int r){
	mx[k]=1<<30; smx[k]=-(1<<30);
	mxs[k]=qy[r+1]-qy[l];
	sum[k]=1ll*mx[k]*mxs[k]%mo;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void UPD(int k,int v){
	sum[k]=(sum[k]+1ll*(v+mo-mx[k])*mxs[k]%mo)%mo;
	mx[k]=v;
}
void pushdown(int k){
	if (mx[k*2]>mx[k]) UPD(k*2,mx[k]);
	if (mx[k*2+1]>mx[k]) UPD(k*2+1,mx[k]);
}
void pushup(int k){
	mx[k]=max(mx[k*2],mx[k*2+1]);
	smx[k]=max((mx[k*2]==mx[k]?smx[k*2]:mx[k*2]),
				mx[k*2+1]==mx[k]?smx[k*2+1]:mx[k*2+1]);
	mxs[k]=(mx[k*2]==mx[k]?mxs[k*2]:0)+
			(mx[k*2+1]==mx[k]?mxs[k*2+1]:0);
	sum[k]=(sum[k*2]+sum[k*2+1])%mo;
}
void change(int k,int l,int r,int x,int y,int v){
	//cout<<k<<' '<<l<<' '<<r<<' '<<x<<' '<<y<<' '<<v<<' '<<mx[k]<<' '<<smx[k]<<endl;
	if (x<=l&&r<=y){
		if (mx[k]<=v) return;
		if (smx[k]<v) return UPD(k,v);
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	pushup(k);
}

bool cmp(node a,node b){
	return a.X<b.X;
}
int Func(int p){
	int top=0;
	For(i,1,K) op[i].resize(0);
	For(i,1,n) if (x[i]>=p)
		op[v[i]].PB(pii(py[i],x[i]));
	For(i,1,K){
		//cout<<i<<' '<<p<<endl;
		if (!op[i].size()) return 0;
		sort(op[i].begin(),op[i].end());
		int m=0,t;
		for (auto j:op[i])
			if (!m||opp[m].fi!=j.fi)
				opp[++m]=j;
		For(j,1,m) pl[j]=1,pr[j]=*qy;
		t=0;
		For(j,1,m){
			for (;t&&opp[q[t]].se>opp[j].se;--t) pr[q[t]]=opp[j].fi;
			if (t) pl[j]=opp[q[t]].fi;	
			q[++t]=j;
		}
		opp[0]=pii(1,0);
		opp[m+1]=pii(*qy,0);
		For(j,1,m) opt[++top]=(node){pl[j],pr[j],L-opp[j].se};
		For(j,1,m+1) opt[++top]=(node){opp[j-1].fi,opp[j].fi,0};
	}
	sort(opt+1,opt+top+1,cmp);
	//For(i,1,top)
	//	cout<<"OPER "<<qy[opt[i].X]<<' '<<qy[opt[i].Y]<<' '<<opt[i].v<<endl;
	
	ll res=0;
	int pos=1;
	build(1,1,(*qy)-1);
	For(i,1,(*qy)-1){
		for (;pos<=top&&opt[pos].X<=i;++pos)
			change(1,1,(*qy)-1,1,opt[pos].Y-1,opt[pos].v);
		change(1,1,(*qy)-1,1,i,0);
		res=(res+1ll*(qy[i+1]-qy[i])*sum[1])%mo;
		//cout<<i<<' '<<qy[i+1]-qy[i]<<' '<<sum[1]<<' '<<qy[i+1]<<' '<<qy[i]<<endl;
	}
	//cout<<p<<' '<<res<<endl;
	return res;
}
int main(){
	scanf("%d%d%d",&n,&K,&L);
	For(i,1,n) scanf("%d%d%d",&x[i],&y[i],&v[i]);
	For(i,1,n) qx[++*qx]=x[i],qy[++*qy]=y[i];
	qy[++*qy]=-1; qy[++*qy]=L;
	qx[++*qx]=-1;
	sort(qx+1,qx+*qx+1);
	sort(qy+1,qy+*qy+1);
	//For(i,1,*qy) cout<<qy[i]<<' '; cout<<endl;
	*qx=unique(qx+1,qx+*qx+1)-qx-1;
	*qy=unique(qy+1,qy+*qy+1)-qy-1;
	//For(i,1,*qy) cout<<qy[i]<<' '; cout<<endl;
	For(i,1,n) py[i]=lower_bound(qy+1,qy+*qy+1,y[i])-qy;
	For(i,2,*qx) ans=(ans+1ll*(qx[i]-qx[i-1])*Func(qx[i]))%mo;
	cout<<(ans+mo)%mo<<endl;
}