#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=20005;
struct L{
	ll b,k;
	L(){}
	L(ll _b,ll _k){
		b=_b; k=_k;
	}
	ll F(ll x){
		return x*k+b;
	}
};
L q[N];
int top,n,k;
int f[N],g[N],a[N],t[N];
bool cmp(L x,L y,L z){
	return 1ll*(x.b-y.b)*(x.k-z.k)<=1ll*(x.b-z.b)*(x.k-y.k);
}
void insert(L x){
	for (;top&&x.k>=q[top].k;top--) x.b=min(x.b,q[top].b);
	for (;top>1&&cmp(q[top-1],q[top],x);top--);
	q[++top]=x;
}
int func(int x){
	if (!top) return 1<<30;
	int l=1,r=top-1,ans=top;
	while (l<=r){
		int mid=(l+r)/2;
		if (q[mid].F(x)<=q[mid+1].F(x))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	return q[ans].F(x);
}
void divide(int l,int r){
	if (l==r) return;
	int mid=(l+r)/2;
	divide(l,mid);
	divide(mid+1,r);
	t[mid]=a[mid];
	t[mid+1]=a[mid+1];
	Rep(i,mid-1,l) t[i]=max(t[i+1],a[i]);
	For(i,mid+2,r) t[i]=max(t[i-1],a[i]);
	top=0;
	for (int i=r,j=l;i>mid;i--){
		for (;j<=mid&&t[j+1]>=t[i];j++)
			if (f[j]<1<<30) insert(L(f[j]-j*t[j+1],t[j+1]));
		g[i]=min(g[i],func(i));
	}
	top=0;
	for (int i=mid+1,j=mid;i<=r;i++){
		for (;j>=l&&t[j+1]<=t[i];j--)
			if (f[j]<1<<30) insert(L(f[j],j));
		g[i]=min(g[i],func(-t[i])+i*t[i]);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) f[i]=max(f[i-1],a[i]);
	For(i,1,n) f[i]=i*f[i];
	For(i,2,k){
		For(j,0,n) g[j]=1<<30;
		divide(1,n);
		For(j,0,n) f[j]=g[j];
	}
	printf("%d\n",f[n]);
}