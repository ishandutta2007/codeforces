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
struct node{
	int L,R,p;
}a[N],b[N];
int n,Q,q[N],ans[N];
vector<int> vC[N*4],vQ[N*4];
pii qq[N*2];
void insertQ(int k,int l,int r,int p,int id){
	vQ[k].PB(id);
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) insertQ(k*2,l,mid,p,id);
	else insertQ(k*2+1,mid+1,r,p,id);
}
void insertC(int k,int l,int r,int id){
	if (a[id].R<q[l]||a[id].L>q[r]) return;
	if (a[id].L<=q[l]&&a[id].R>=q[r])
		return vC[k].PB(id),void(0);
	int mid=(l+r)/2;
	insertC(k*2,l,mid,id);
	insertC(k*2+1,mid+1,r,id);
}
void solve(int k,int l,int r){
	int top=0,S=0;
	for (auto i:vQ[k]) qq[++top]=pii(b[i].L+b[i].p,i);
	for (auto i:vC[k]) qq[++top]=pii(a[i].L+a[i].p,0);
	sort(qq+1,qq+top+1);
	For(i,1,top)
		if (qq[i].se==0) ++S;
		else ans[qq[i].se]+=S;
	top=0; S=0;
	for (auto i:vQ[k]) qq[++top]=pii(b[i].L-b[i].p,i);
	for (auto i:vC[k]) qq[++top]=pii(a[i].L-a[i].p,0);
	sort(qq+1,qq+top+1);
	Rep(i,top,1)
		if (qq[i].se==0) ++S;
		else ans[qq[i].se]-=S;
	if (l==r) return;
	int mid=(l+r)/2;
	solve(k*2,l,mid);
	solve(k*2+1,mid+1,r);
}
/*
bi-prefj<=incj-pi
bi+pi<=incj+prefj


prefj-bi>incj-pi
pi-bi>incj-prefj
*/
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i].L);
	For(i,1,n) scanf("%d",&a[i].R);
	For(i,1,n) scanf("%d",&a[i].p);
	For(i,1,Q) scanf("%d",&b[i].L);
	For(i,1,Q) scanf("%d",&b[i].p);
	//Q=1;
	For(i,1,Q) q[++*q]=b[i].L;
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	For(i,1,Q){
		int p=lower_bound(q+1,q+*q+1,b[i].L)-q;
		insertQ(1,1,*q,p,i);
	}
	For(i,1,n) insertC(1,1,*q,i);
	solve(1,1,*q);
	For(i,1,Q) printf("%d ",ans[i]);
}