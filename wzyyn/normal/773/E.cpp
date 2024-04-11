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
const int N=500005;
int sz[N*8];
int v1[N*8];
int v2[N*8];
int n;
void pushup(int k){
	sz[k]=sz[k*2]+sz[k*2+1];
	v1[k]=max(v1[k*2],sz[k*2]+v1[k*2+1]);
	v2[k]=min(v2[k*2]+sz[k*2+1],v2[k*2+1]);
}
void build(int k,int l,int r){
	if (l==r){
		sz[k]=0;
		v1[k]=-(1<<30);
		v2[k]=1<<30;
		return;
	}
	int mid=(l+r+2*N)/2-N;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int p){
	if (l==r){
		sz[k]++;
		v1[k]=l+sz[k];
		v2[k]=l;
		return;
	}
	int mid=(l+r+2*N)/2-N;
	if (p<=mid) change(k*2,l,mid,p);
	else change(k*2+1,mid+1,r,p);
	pushup(k);
}
pii find1(int k,int l,int r,int v){
	if (l==r) return pii(l,min(-v,l));
	int mid=(l+r+2*N)/2-N;
	if (v+v1[k*2]>=0) return find1(k*2,l,mid,v);
	return find1(k*2+1,mid+1,r,v+sz[k*2]);
}
int find2(int k,int l,int r,int p){
	//cout<<k<<' '<<l<<' '<<r<<' '<<p<<endl;
	if (l==r) return v2[k];
	int mid=(l+r+2*N)/2-N;
	if (p>mid) return find2(k*2+1,mid+1,r,p);
	return min(find2(k*2,l,mid,p)+sz[k*2+1],v2[k*2+1]);
}
int ask(int k,int l,int r,int p){
	if (p>r) return 0;
	if (l==r) return sz[k];
	int mid=(l+r+2*N)/2-N;
	if (p>mid) return ask(k*2+1,mid+1,r,p);
	return ask(k*2,l,mid,p)+sz[k*2+1];
}
int main(){
	scanf("%d",&n);
	build(1,-N,N);
	change(1,-N,N,N);
	while (n--){
		int x;
		scanf("%d",&x);
		change(1,-N,N,x);
		pii tmp=find1(1,-N,N,0);
		//cout<<tmp.fi<<' '<<tmp.se<<endl;
		int ans=find2(1,-N,N,tmp.fi);
		//cout<<ans<<endl;
		ans=min(ans,tmp.se+ask(1,-N,N,tmp.fi));
		printf("%d\n",ans-1);
	}
}
/*
sz:
v1:max(<=v)+
v2:max(>v)+ 
*/