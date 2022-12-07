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
int n,Q,top,a[N],pr[N];
set<int> S[N];
struct node{
	int x,y,v;
}q[N*10],qq[N*10];
ll t[N],ans[N];
void change(int x,int v){
	for (;x;x-=x&(-x)) t[x]+=v;
}
ll ask(int x){
	ll ans=0;
	for (;x<=n;x+=x&(-x)) ans+=t[x];
	return ans;
}
void solve(int l,int r){
	if (l==r) return;
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	int p1=l,p2=mid+1,p3=l;
	for (;p1<=mid||p2<=r;){
		if (p1>mid||(p2<=r&&q[p2].x<q[p1].x)){
			if (q[p2].v>N) ans[q[p2].v-N]+=ask(q[p2].y);
			qq[p3++]=q[p2++];
		}
		else{
			if (q[p1].v<N) change(q[p1].y,q[p1].v);
			qq[p3++]=q[p1++];
		}
	}
	For(i,l,mid) if (q[i].v<N) change(q[i].y,-q[i].v);
	For(i,l,r) q[i]=qq[i];
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n){
		if (pr[a[i]]) q[++top]=(node){i,pr[a[i]],i-pr[a[i]]};
		pr[a[i]]=i; S[a[i]].insert(i);
	}
	For(i,1,Q){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==2) q[++top]=(node){y,x,N+i};
		else{
			int pr,nx;
			set<int>::iterator it;
			S[a[x]].erase(x);
			it=S[a[x]].lower_bound(x);
			nx=(it==S[a[x]].end()?-1:*it);
			pr=(it==S[a[x]].begin()?-1:*(--it));
			if (nx!=-1) q[++top]=(node){nx,x,x-nx};
			if (pr!=-1) q[++top]=(node){x,pr,pr-x};
			if (nx!=-1&&pr!=-1) q[++top]=(node){nx,pr,nx-pr};
			it=S[y].lower_bound(x);
			nx=(it==S[y].end()?-1:*it);
			pr=(it==S[y].begin()?-1:*(--it));
			if (nx!=-1) q[++top]=(node){nx,x,nx-x};
			if (pr!=-1) q[++top]=(node){x,pr,x-pr};
			if (nx!=-1&&pr!=-1) q[++top]=(node){nx,pr,pr-nx};
			S[a[x]=y].insert(x);
			ans[i]=-233;
		}
	}
	solve(1,top);
	For(i,1,Q) if (ans[i]>=0) printf("%lld\n",ans[i]);
}