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
const int N=1005,M=30005;
vector<int> vec[M*4];
int L[M],R[M],a[M],v[M];
int f[20][N],n,Q,K,vis[M];
void insert(int k,int l,int r,int id){
	//cout<<k<<' '<<l<<' '<<r<<' '<<id<<' '<<L[id]<<' '<<R[id]<<endl;
	if (L[id]<=l&&r<=R[id])
		return vec[k].PB(id),void(0);
	int mid=(l+r)/2;
	if (L[id]<=mid) insert(k*2,l,mid,id);
	if (R[id]>mid) insert(k*2+1,mid+1,r,id);
}
void solve(int k,int l,int r,int p){
	for (auto i:vec[k]) Rep(j,K,a[i])
		f[p][j]=max(f[p][j],f[p][j-a[i]]+v[i]);
	if (l==r){
		if (!vis[l]) return;
		int ans=0;
		Rep(i,K,1) ans=(ans*10000019ll+f[p][i])%1000000007;
		printf("%d\n",ans);
		return;
	}
	int mid=(l+r)/2;
	memcpy(f[p+1],f[p],sizeof(f[p]));
	solve(k*2,l,mid,p+1);
	memcpy(f[p+1],f[p],sizeof(f[p]));
	solve(k*2+1,mid+1,r,p+1);
}
int main(){
	scanf("%d%d",&n,&K);
	For(i,1,n) scanf("%d%d",&v[i],&a[i]),L[i]=1;
	scanf("%d",&Q); 
	For(i,1,Q){
		int tp,x,y;
		scanf("%d",&tp);
		if (tp==1){
			L[++n]=i;
			scanf("%d%d",&v[n],&a[n]);
		}
		if (tp==2){
			scanf("%d",&x);
			R[x]=i;
		}
		if (tp==3)
			vis[i]=1;
	} 
	For(i,1,n) if (!R[i]) R[i]=Q;
	For(i,1,n) insert(1,1,Q,i);
	solve(1,1,Q,1);
}