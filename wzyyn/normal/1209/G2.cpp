#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define y1 wzpakking
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=200005;
int n,Q,a[N],cnt[N];
set<int> S[N];
struct node{
	int S,tg,mn;
	int pl,pr;
	int mxl,mxr,mx;
};
node operator +(node a,node b){
	node ans;
	ans.mn=min(a.mn,b.mn);
	ans.mx=max(a.mx,b.mx);
	ans.S=ans.tg=0;
	if (a.mn!=ans.mn) a.pl=a.pr=-1,a.S=0;
	if (b.mn!=ans.mn) b.pl=b.pr=-1,b.S=0;
	ans.S=a.S+b.S;
	ans.pl=(a.pl!=-1?a.pl:b.pl);
	ans.pr=(b.pr!=-1?b.pr:a.pr);
	if (a.pl!=-1) ans.mxl=a.mxl;
	else ans.mxl=max(a.mx,b.mxl);
	if (b.pr!=-1) ans.mxr=b.mxr;
	else ans.mxr=max(b.mx,a.mxr);
	if (a.pr!=-1&&b.pl!=-1) ans.S+=max(a.mxr,b.mxl);
	return ans;	
}
node t[N*4];
void build(int k,int l,int r){
	if (l==r){
		t[k].S=t[k].tg=t[k].mn=0;
		t[k].pl=t[k].pr=l;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
void addv(int k,int v){
	t[k].mn+=v;
	t[k].tg+=v;
}
void pushdown(int k){
	if (!t[k].tg) return;
	addv(k*2,t[k].tg);
	addv(k*2+1,t[k].tg);
	t[k].tg=0;
}
void change(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y)
		return addv(k,v);
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else{
		change(k*2,l,mid,x,mid,v);
		change(k*2+1,mid+1,r,mid+1,y,v);
	}
	t[k]=t[k*2]+t[k*2+1];
}
void changev(int k,int l,int r,int p,int v){
	if (l==r){
		t[k].mxl=t[k].mx=v;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (p<=mid) changev(k*2,l,mid,p,v);
	else changev(k*2+1,mid+1,r,p,v);
	t[k]=t[k*2]+t[k*2+1];
}
void erasev(int x){
	if (!cnt[x]) return;
	changev(1,0,n,*S[x].begin(),0);
}
void insertv(int x){
	if (!cnt[x]) return;
	changev(1,0,n,*S[x].begin(),cnt[x]);
}
void erase(int x){
	if (cnt[x]<2) return;
	int l=*S[x].begin();
	int r=*(--S[x].end());
	change(1,0,n,l,r-1,-1);
}
void insert(int x){
	if (cnt[x]<2) return;
	int l=*S[x].begin();
	int r=*(--S[x].end());
	change(1,0,n,l,r-1,1);
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n){
		scanf("%d",&a[i]);
		S[a[i]].insert(i);
		++cnt[a[i]];
	}
	build(1,0,n);
	For(i,1,N-1) insertv(i);
	For(i,1,N-1) insert(i);
	printf("%d\n",n-t[1].S);
	For(i,1,Q){
		int x,v1,v2;
		scanf("%d%d",&x,&v2); v1=a[x];
		erase(v1); erase(v2);
		erasev(v1); erasev(v2);
		S[v1].erase(x); --cnt[v1];
		S[v2].insert(x); ++cnt[v2];
		insertv(v1); insertv(v2);
		insert(v1); insert(v2);
		a[x]=v2;
		printf("%d\n",n-t[1].S);
	}
}