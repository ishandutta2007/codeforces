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
const int N=100005;
int n,a[N],la[N];
int t[N*4],vis[N];
void change(int k,int l,int r,int x,int v){
	if (l==r){
		t[k]=v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,v);
	else change(k*2+1,mid+1,r,x,v);
	t[k]=min(t[k*2],t[k*2+1]);
}
int find(int k,int l,int r,int v){
	if (l==r) return l;
	int mid=(l+r)/2;
	if (t[k*2]<v) return find(k*2,l,mid,v);
	return find(k*2+1,mid+1,r,v);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n){
		int x=a[i];
		if (la[x]+1!=i)
			vis[find(1,1,n+1,la[x]+1)]=1;
		change(1,1,n+1,x,i);
		la[x]=i;
	}
	For(i,1,n+1)
		if (la[i]&&la[i]!=n)
			vis[find(1,1,n+1,la[i]+1)]=1;
	vis[find(1,1,n+1,1)]=1;
	int ans=1;
	for (;vis[ans];++ans);
	cout<<ans<<endl;	
}