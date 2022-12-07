#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=50005;
pll q[N];
ll k;
int mo,top,s[N];
int n,Q;
struct mat{
	int a[2][2];
	mat(){
		memset(a,0,sizeof(a));
	}
	mat operator *(const mat &b)const{
		mat ans;
		For(i,0,1) For(j,0,1) For(k,0,1)
			ans.a[i][k]=(ans.a[i][k]+1ll*a[i][j]*b.a[j][k])%mo;
		return ans;
	}
}t[N*4];
struct node{
	int v1,v2;
	ll T;
}a[N*2];
mat power(mat a,ll b){
	mat ans;
	ans.a[0][0]=ans.a[1][1]=1;
	for (;b;b/=2,a=a*a)
		if (b&1) ans=ans*a;
	return ans;
}
pii work(pii a,mat b){
	int x=(1ll*a.fi*b.a[0][0]+1ll*a.se*b.a[1][0])%mo;
	int y=(1ll*a.fi*b.a[0][1]+1ll*a.se*b.a[1][1])%mo;
	return pii(x,y);
}
void build(int k,int l,int r){
	if (l==r){
		t[k].a[1][0]=1;
		t[k].a[0][1]=s[(l+n-2%n)%n];
		t[k].a[1][1]=s[(l+n-1)%n];
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]*t[k*2+1];
}
mat ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	else if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	else return ask(k*2,l,mid,x,mid)*ask(k*2+1,mid+1,r,mid+1,y);
}
void work(pii &ans,ll l,ll r){
	//printf("%lld %lld\n",l,r);
	if (l>r) return;
	ll bl=l/n,br=r/n;
	if (bl==br) ans=work(ans,ask(1,0,n-1,l%n,r%n));
	else{
		ans=work(ans,ask(1,0,n-1,l%n,n-1));
		ans=work(ans,power(t[1],br-bl-1));
		ans=work(ans,ask(1,0,n-1,0,r%n));
	}
}
int main(){
	scanf("%lld%d%d",&k,&mo,&n);
	For(i,0,n-1) scanf("%d",&s[i]);
	scanf("%d",&Q);
	For(i,1,Q) scanf("%lld%lld",&q[i].fi,&q[i].se);
	sort(q+1,q+Q+1);
	For(i,1,Q){
		if (q[i].fi==q[i-1].fi+1)
			a[top].v2=q[i].se;
		else a[++top]=(node){s[(q[i].fi-1)%n],q[i].se,q[i].fi+1};
		a[++top]=(node){q[i].se,s[(q[i].fi+1)%n],q[i].fi+2};
	}
	build(1,0,n-1);
	ll pos=1;
	pii ans(0,1%mo);
	For(i,1,top) if (a[i].T<=k){
		work(ans,pos+1,a[i].T-1);
		//printf("INFO %lld %d %d\n",a[i].T,ans.fi,ans.se);
		int tmp=(1ll*ans.se*a[i].v2+1ll*ans.fi*a[i].v1)%mo;
		ans.fi=ans.se; ans.se=tmp;
		//printf("INFO %lld %d %d %d %d\n",a[i].T,a[i].v1,a[i].v2,ans.fi,ans.se);
		pos=a[i].T;
	}
	work(ans,pos+1,k);
	printf("%d\n",k==0?ans.fi:ans.se);
}
/*
5 8
3
1 2 1
2
7 3
5 4
 
1 2 1 1 2 4 1 3 1 1
0 1 2 4 6 0 
*/