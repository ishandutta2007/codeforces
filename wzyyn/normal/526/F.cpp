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
const int N=300005;
int a[N],b[N],n;
int mn[N],mx[N];
int v[N],g[N];
ll ans;
void calc(int *a,int *b){
	int m=*b;
	mn[0]=1<<30; mx[0]=0;
	For(i,1,m){
		mn[i]=min(mn[i-1],b[i]);
		mx[i]=max(mx[i-1],b[i]);
	}
	int mna=1<<30,mxa=0,l=1,r=1;
	For(i,1,*a){
		mna=min(mna,a[i]);
		mxa=max(mxa,a[i]);
		int d=(mxa-mna+1)-i;
		if (d>0&&d<=m&&mn[d]>mna&&mx[d]<mxa) ++ans;
		for (;r<=m&&mx[r]<mxa;++r) ++g[r+mn[r]-1];
		for (;l<r&&mn[l]>mna;++l) --g[l+mn[l]-1];
		ans+=g[mxa-i];
	}
	For(i,1,m)
		g[i+mn[i]-1]=0;
}
//v1+v2==mx-mn+1
//v1-mx==-v2-mn+1
void solve(int l,int r){
	if (l==r) return;
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	*a=*b=0;
	For(i,mid+1,r) a[++*a]=v[i];
	Rep(i,mid,l) b[++*b]=v[i];
	calc(a,b);
	calc(b,a);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		scanf("%d",&v[x]);
	}
	solve(1,n);
	printf("%lld\n",ans+n);
}