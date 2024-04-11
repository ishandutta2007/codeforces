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
int n,v[N],Q,a[N],b[N];
vector<int> v1[N],v2[N];
struct node{
	int a[105];
}t[1<<19];
node operator +(node a,node b){
	node ans;
	For(i,1,100) ans.a[i]=b.a[a.a[i]];
	return ans;
} 
void build(int k,int l,int r){
	if (l==r){
		For(i,1,100) t[k].a[i]=i;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
void change(int k,int l,int r,int p,int v1,int v2){
	if (l==r){
		t[k].a[v1]=v2;
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v1,v2);
	else change(k*2+1,mid+1,r,p,v1,v2);
	t[k]=t[k*2]+t[k*2+1];
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&v[i]);
	scanf("%d",&Q);
	For(i,1,Q){
		int l,r;
		scanf("%d%d%d%d",&l,&r,&a[i],&b[i]);
		v1[l].PB(i); v2[r+1].PB(i);
	}
	build(1,1,Q);
	For(i,1,n){
		for (auto j:v1[i])
			change(1,1,Q,j,a[j],b[j]);
		for (auto j:v2[i])
			change(1,1,Q,j,a[j],a[j]);
		v[i]=t[1].a[v[i]];
	}
	For(i,1,n)
		printf("%d ",v[i]);
}