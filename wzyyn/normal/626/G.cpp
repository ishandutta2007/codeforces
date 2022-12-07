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
const int N=200005;
const double eps=1e-8;
struct node{
	double v1,v2,S;
	int id1,id2;
}t[N*4];
int n,m,Q;
int a[N],b[N];
double v[N];
node build(int x){
	node ans;
	int oa=min(b[x],a[x]);
	ans.S=v[x]*oa/(oa+b[x]);
	ans.id1=ans.id2=x;
	ans.v1=(a[x]>=b[x]?0:v[x]*(a[x]+1)/(a[x]+b[x]+1)-ans.S);
	if (!a[x]) ans.v2=-1e18;
	else ans.v2=(a[x]>b[x]?0:v[x]*(a[x]-1)/(a[x]+b[x]-1)-ans.S);
	return ans;
}
void pushup(int k){
	t[k].S=t[k*2].S+t[k*2+1].S;
	t[k].v1=max(t[k*2].v1,t[k*2+1].v1);
	t[k].v2=max(t[k*2].v2,t[k*2+1].v2);
	t[k].id1=(t[k].v1==t[k*2].v1?t[k*2].id1:t[k*2+1].id1);
	t[k].id2=(t[k].v2==t[k*2].v2?t[k*2].id2:t[k*2+1].id2);
}
void build(int k,int l,int r){
	if (l==r){
		t[k]=build(l);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int x){
	if (l==r){
		t[k]=build(l);
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x);
	else change(k*2+1,mid+1,r,x);
	pushup(k);
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n) scanf("%lf",&v[i]);
	For(i,1,n) scanf("%d",&b[i]);
	build(1,1,n);
	For(i,1,m){
		int x=t[1].id1;
		++a[x];
		change(1,1,n,x);
	}
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x==1) ++b[y]; else --b[y];
		change(1,1,n,y);
		for (;t[1].v1+t[1].v2>eps;){
			x=t[1].id1,y=t[1].id2;
			++a[x]; --a[y];
			change(1,1,n,x);
			change(1,1,n,y);
		}
		printf("%.10lf\n",t[1].S);
	}
}