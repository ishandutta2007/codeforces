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
const int N=200005;
struct node{
	int l,r,co;
	ll v;
}q[N];
ll t[N],a[N];
int n,tot,vis[N],nx[N];
int f[N][2],co[N];
int fr[N][2][2];
void init_node(){
	tot=0;
	memcpy(t,a,sizeof(t));
	memset(vis,0,sizeof(vis));
	For(i,1,n) co[i]=-1;
	int lap=0;
	For(i,1,n) if (t[i]){
		if (lap&&t[i]<=t[lap]){
			For(j,lap,i-1) t[j]=t[lap],co[j]=0;
			co[i]=(t[i]==t[lap]?0:1);
		}
		lap=i;
	}
	q[++tot]=(node){0,0,1,0};
	For(i,1,n)
		if (t[i]&&!vis[i]){
			int j=i;
			for (;j<n&&t[j+1]&&t[j+1]<=t[j];++j);
			For(p,i,j) vis[p]=1;
			if (i==j) q[++tot]=(node){i,j,-1,t[j]};
			else q[++tot]=(node){i,j,co[j],t[j]}; 
		}
}
int CO(int x){
	return n+1-x;
}
void update1(int i,int j,int v1,ll v2){
	if (q[i+1].co==0) return;
	int l=v1,r=q[i+1].l-1;
	l=CO(l); r=CO(r); swap(l,r);
	v2=q[i+1].v-CO(q[i+1].r)-v2;
	if (r+1<l) return;
	For(ele,0,r-l+1){
		ll sl=1ll*ele*(l+l+ele-1)/2;
		ll sr=1ll*ele*(r+r-ele+1)/2;
		if (sl<=v2&&v2<=sr){
			f[i+1][1]=1;
			fr[i+1][1][0]=j;
			fr[i+1][1][1]=ele;
		}
	}
}
void update2(int i,int j,int v1,ll v2){
	if (q[i+1].co!=0) return;
	int l=v1,r=q[i+1].l-1;
	l=CO(l); r=CO(r); swap(l,r);
	v2=q[i+1].v-1-CO(q[i+1].l)-v2;
	//cout<<"UPD2 "<<l<<' '<<r<<' '<<v1<<' '<<v2<<endl;
	if (r+1<l) return;
	For(ele,0,r-l+1){
		ll sl=1ll*ele*(l+l+ele-1)/2;
		ll sr=1ll*ele*(r+r-ele+1)/2;
		if (sr>=v2){
			ll at=q[i+1].l+max(0ll,sl-v2);
			if (at>=n+1) continue;
			if (nx[at]>q[i+1].l+sr-v2) continue;
			f[i+1][1]=1;
			fr[i+1][1][0]=nx[at];
			fr[i+1][1][1]=ele;
		}
	}
}
void update0(int i,int j,int v1,ll v2){
	if (q[i+1].co==1) return;
	int l=v1,r=q[i+1].l-1;
	//cout<<v2<<endl;
	l=n+1-l; r=n+1-r; swap(l,r);
	v2=q[i+1].v-1-CO(q[i+1].r+1)-v2;
	if (r+1<l) return;
	For(ele,0,r-l+1){
		ll sl=1ll*ele*(l+l+ele-1)/2;
		ll sr=1ll*ele*(r+r-ele+1)/2;
		if (sr>=v2){
			ll at=q[i+1].r+1+max(0ll,sl-v2);
			//cout<<at<<endl;
			if (at<f[i+1][0]){
				f[i+1][0]=at;
				fr[i+1][0][0]=j;
				fr[i+1][0][1]=ele;
			}
		}
	}
}
void construct1(int i,int j,ll v1,ll v2,int ele){
	assert(q[i+1].co!=0);
	int l=v1,r=q[i+1].l-1;
	l=CO(l); r=CO(r); swap(l,r);
	v2=q[i+1].v-CO(q[i+1].r)-v2;
	co[q[i+1].r]=1;
	if (r<l) r=l-1;
	//cout<<"C1 "<<l<<' '<<r<<' '<<ele<<' '<<v2<<endl;
	For(i,l,r) if (ele){
		ll tmp=v2-i;
		ll sl=1ll*(ele-1)*((i+1)+(i+1)+(ele-1)-1)/2;
		ll sr=1ll*(ele-1)*(r+r-(ele-1)+1)/2;
		if (sl<=tmp&&tmp<=sr) co[CO(i)]=1,v2-=i,ele--;
	}
	assert(!ele);
}
void construct0(int i,int j,ll v1,ll v2,int ele){
	assert(q[i+1].co!=1);
	int l=v1,r=q[i+1].l-1;
	l=CO(l); r=CO(r); swap(l,r);
	v2=q[i+1].v-1-CO(f[i+1][0])-v2;
	co[f[i+1][0]]=1;
	if (r<l) r=l-1;
	//cout<<"CONSTRUCT "<<l<<' '<<r<<' '<<v1<<' '<<v2<<' '<<ele<<endl;
	For(i,l,r) if (ele){
		ll tmp=v2-i;
		ll sl=1ll*(ele-1)*((i+1)+(i+1)+(ele-1)-1)/2;
		ll sr=1ll*(ele-1)*(r+r-(ele-1)+1)/2;
		if (sl<=tmp&&tmp<=sr) co[CO(i)]=1,v2-=i,ele--;
	}
	assert(!ele);
}
void construct(int i,int p){
	if (i==1) return;
	int j=fr[i][p][0];
	construct(i-1,j);
	//cout<<"C "<<i<<' '<<j<<' '<<p<<endl;
	ll v1=(j==0?f[i-1][j]+1:q[i-1].r+1);
	ll v2=(j==0?q[i-1].v-1:q[i-1].v);
	if (p==0) construct0(i-1,j,v1,v2,fr[i][p][1]);
	else construct1(i-1,j,v1,v2,fr[i][p][1]);
}
void find_solu(){
	memset(f,30,sizeof(f));
	f[1][1]=1;
	For(i,1,tot-1) For(j,0,1){
		if (f[i][j]>=n+1) continue;
		ll v1=(j==0?f[i][j]+1:q[i].r+1);
		ll v2=(j==0?q[i].v-1:q[i].v);
		update0(i,j,v1,v2);
		update1(i,j,v1,v2);
	}
	//cout<<f[tot][0]<<' '<<f[tot][1]<<endl;
	if (f[tot][0]>n+1&&f[tot][1]>n+1) return;
	construct(tot,f[tot][1]<=n+1);
	For(i,1,n) if (co[i]==-1) co[i]=0;
	For(i,1,n) printf("%d",co[i]);
	exit(0);
}
void find_solu2(){
	nx[n+1]=n+1;
	assert(q[tot].r!=q[tot].l);
	For(i,q[tot].l,q[tot].r) if (!a[i]) nx[i]=i;
	Rep(i,n,1) if (!nx[i]) nx[i]=nx[i+1];
	For(i,tot-1,tot-1) For(j,0,1){
		//cout<<i<<' '<<j<<endl;
		if (f[i][j]>=n+1) continue;
		ll v1=(j==0?f[i][j]+1:q[i].r+1);
		ll v2=(j==0?q[i].v-1:q[i].v);
		update2(i,j,v1,v2);
	}
	if (f[tot][1]>n+1) return;
	q[tot].r=fr[tot][1][0];
	q[tot].co=1; q[tot].v--;
	//cout<<"find "<<q[tot].r<<' '<<q[tot].v<<endl;
	find_solu();
	exit(0);
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	ll mxv=0;
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,n) mxv=max(mxv,a[i]);
	if (!mxv){
		For(i,1,n) putchar('0');
		puts("");
		return 0;
	}
	init_node();
	find_solu();
	find_solu2();
	assert(0);
}
//an O(n) solution of div.1 E